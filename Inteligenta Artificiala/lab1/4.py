import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from PIL import Image
from sklearn.preprocessing import MinMaxScaler, StandardScaler

# Citirea fisierului CSV pentru problema 1
file_path = "lab1/data/surveyDataSience.csv"
df = pd.read_csv(file_path, skiprows=1, low_memory=False)

# Normalizare durata anilor de studii universitare si vechimea in programare
education_mapping = {
    "Bachelor’s degree": 3,
    "Master’s degree": 5,
    "Doctoral degree": 8,
    "Some college/university study without earning a bachelor’s degree": 2,
    "Professional degree": 5,
    "I prefer not to answer": None,
    "No formal education past high school": 0,
}
df["Years of Higher Education"] = df[
    "What is the highest level of formal education that you have attained or plan to attain within the next 2 years?"
].map(education_mapping)

experience_mapping = {
    "< 1 years": 0.5,
    "1-3 years": 2,
    "3-5 years": 4,
    "5-10 years": 7.5,
    "10-20 years": 15,
    "20+ years": 25,
}
df["Years of Programming Experience"] = df[
    "For how many years have you been writing code and/or programming?"
].map(experience_mapping)

# Inlocuire valori NaN cu media coloanei
for column in ["Years of Higher Education", "Years of Programming Experience"]:
    df[column].fillna(df[column].mean(), inplace=True)

# Aplicare Min-Max Scaling si Standard Scaling pentru aceste variabile
scaler_minmax = MinMaxScaler()
scaler_standard = StandardScaler()

df[["Years of Higher Education MinMax", "Years of Programming Experience MinMax"]] = (
    scaler_minmax.fit_transform(
        df[["Years of Higher Education", "Years of Programming Experience"]]
    )
)
df[["Years of Higher Education Std", "Years of Programming Experience Std"]] = (
    scaler_standard.fit_transform(
        df[["Years of Higher Education", "Years of Programming Experience"]]
    )
)

print("Durata anilor de studii universitare normalizata (MinMax si Standard):")
print(df[["Years of Higher Education MinMax", "Years of Higher Education Std"]].head())
print("Vechimea in programare normalizata (MinMax si Standard):")
print(
    df[
        [
            "Years of Programming Experience MinMax",
            "Years of Programming Experience Std",
        ]
    ].head()
)

# Problema 2 - Normalizare valorile pixelilor din imagini
image_folder = "lab1/data/images"
image_files = [
    f for f in os.listdir(image_folder) if f.endswith((".png", ".jpg", ".jpeg"))
]

if image_files:
    image_path = os.path.join(image_folder, image_files[0])
    image = Image.open(image_path).convert("L")  # Convertim la grayscale
    image_array = np.array(image, dtype=np.float32)

    # Normalizare Min-Max
    image_minmax = (image_array - image_array.min()) / (
        image_array.max() - image_array.min()
    )

    # Normalizare Standard (z-score)
    image_std = (image_array - np.mean(image_array)) / np.std(image_array)

    fig, axes = plt.subplots(1, 3, figsize=(15, 5))
    axes[0].imshow(image, cmap="gray")
    axes[0].set_title("Original")
    axes[1].imshow(image_minmax, cmap="gray")
    axes[1].set_title("Min-Max Scaling")
    axes[2].imshow(image_std, cmap="gray")
    axes[2].set_title("Standard Scaling")
    for ax in axes:
        ax.axis("off")
    plt.show()

    print("Valorile pixelilor normalizate (MinMax si Standard) afisate grafic.")

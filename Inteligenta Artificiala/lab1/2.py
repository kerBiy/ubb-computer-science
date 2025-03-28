import os
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image, ImageFilter

# Folderul unde sunt salvate imaginile
image_folder = "lab1/data/images"
image_files = [
    f for f in os.listdir(image_folder) if f.endswith((".png", ".jpg", ".jpeg"))
]

# 1. Vizualizarea unei imagini
image_path = os.path.join(image_folder, image_files[0])
image = Image.open(image_path)
plt.figure(figsize=(5, 5))
plt.imshow(image)
plt.title("Imagine originala")
plt.axis("off")
plt.show()

# 2. Redimensionarea imaginilor la 128x128 si vizualizare in format tabelar
resized_images = [
    Image.open(os.path.join(image_folder, img)).resize((128, 128))
    for img in image_files
]

fig, axes = plt.subplots(1, len(resized_images), figsize=(15, 5))
for ax, img, name in zip(axes, resized_images, image_files):
    ax.imshow(img)
    ax.set_title(name)
    ax.axis("off")
plt.show()

# 3. Transformarea imaginilor in format gray-levels si vizualizare
gray_images = [img.convert("L") for img in resized_images]

fig, axes = plt.subplots(1, len(gray_images), figsize=(15, 5))
for ax, img, name in zip(axes, gray_images, image_files):
    ax.imshow(img, cmap="gray")
    ax.set_title(name + " (gray)")
    ax.axis("off")
plt.show()

# 4. Blur aplicat pe o imagine si afisare in format before-after
blurred_image = image.filter(ImageFilter.GaussianBlur(5))

fig, axes = plt.subplots(1, 2, figsize=(10, 5))
axes[0].imshow(image)
axes[0].set_title("Original")
axes[0].axis("off")
axes[1].imshow(blurred_image)
axes[1].set_title("Blurred")
axes[1].axis("off")
plt.show()

# 5. Detectarea muchiilor intr-o imagine si afisare in format before-after
edges_image = image.convert("L").filter(ImageFilter.FIND_EDGES)

fig, axes = plt.subplots(1, 2, figsize=(10, 5))
axes[0].imshow(image, cmap="gray")
axes[0].set_title("Original")
axes[0].axis("off")
axes[1].imshow(edges_image, cmap="gray")
axes[1].set_title("Edges")
axes[1].axis("off")
plt.show()

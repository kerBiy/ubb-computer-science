import pandas as pd

# Citirea fisierului CSV
file_path = "lab1/data/surveyDataSience.csv"
df = pd.read_csv(file_path, skiprows=1)

# 1. Numarul total de respondenti
num_respondents = df.shape[0]
print(num_respondents)

# 2. Numarul si tipul atributelor disponibile pentru fiecare respondent
num_attributes = df.shape[1]
attribute_types = df.dtypes.value_counts()
print("Numar de atribute: ", num_attributes)
print("Tipuri de atribute: ", attribute_types.to_dict())

# 3. Numarul de respondenti cu date complete pentru primele 7 coloane
relevant_columns = df.columns[:7]
num_complete_relevant_respondents = df[relevant_columns].dropna().shape[0]
print("Numar respondenti cu date complete: ", num_complete_relevant_respondents)

# 4. Durata medie a studiilor superioare
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

mean_years_all = df["Years of Higher Education"].mean()
df_romania = df[df["In which country do you currently reside?"] == "Romania"]
mean_years_romania = df_romania["Years of Higher Education"].mean()
df_romania_women = df_romania[
    df_romania["What is your gender? - Selected Choice"] == "Woman"
]
mean_years_romania_women = df_romania_women["Years of Higher Education"].mean()

print("Durata medie a studiilor (toti): ", mean_years_all)
print("Durata medie a studiilor (Romania): ", mean_years_romania)
print("Durata medie a studiilor (Femei Romania): ", mean_years_romania_women)

# 5. Numarul de femei din Romania cu date complete
num_complete_romania_women = df_romania_women[relevant_columns].dropna().shape[0]
print("Numar femei Romania cu date complete: ", num_complete_romania_women)

# 6. Numarul de femei din Romania care programeaza in Python si C++
python_col = "What programming languages do you use on a regular basis? (Select all that apply) - Selected Choice - Python"
cpp_col = "What programming languages do you use on a regular basis? (Select all that apply) - Selected Choice - C++"

num_romania_women_python = df_romania_women[df_romania_women[python_col].notna()].shape[
    0
]
num_romania_women_cpp = df_romania_women[df_romania_women[cpp_col].notna()].shape[0]

print("Numar femei Romania Python: ", num_romania_women_python)
print("Numar femei Romania C++: ", num_romania_women_cpp)

# 7. Intervalul de varsta cu cele mai multe femei care programeaza in Python si C++
age_col = "What is your age (# years)?"
most_common_age_python = (
    df_romania_women[df_romania_women[python_col].notna()][age_col].mode()[0]
    if num_romania_women_python > 0
    else None
)
most_common_age_cpp = (
    df_romania_women[df_romania_women[cpp_col].notna()][age_col].mode()[0]
    if num_romania_women_cpp > 0
    else None
)

print("Interval varsta Python: ", most_common_age_python)
print("Interval varsta C++: ", most_common_age_cpp)

# 8. Domeniul de valori posibile si valorile extreme pentru fiecare atribut
attribute_stats = {}
for column in df.columns:
    unique_values = df[column].dropna().unique()
    num_unique = len(unique_values)
    min_value = df[column].min() if df[column].dtype in ["int64", "float64"] else None
    max_value = df[column].max() if df[column].dtype in ["int64", "float64"] else None
    attribute_stats[column] = {
        "Numar de valori posibile": num_unique,
        "Valoare minima": min_value,
        "Valoare maxima": max_value,
        "Exemple de valori": unique_values[:5],
    }
df_attribute_stats = pd.DataFrame.from_dict(attribute_stats, orient="index")

# 9. Transformarea vechimii in programare in numar de ani
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

# Calcularea momentelor statistice pentru experienta in programare
experience_min = df["Years of Programming Experience"].min()
experience_max = df["Years of Programming Experience"].max()
experience_mean = df["Years of Programming Experience"].mean()
experience_std = df["Years of Programming Experience"].std()
experience_median = df["Years of Programming Experience"].median()

print("Experienta minima (ani): ", experience_min)
print("Experienta maxima (ani): ", experience_max)
print("Experienta medie (ani): ", experience_mean)
print("Deviatie standard experienta: ", experience_std)
print("Mediana experientei (ani): ", experience_median)

import numpy as np
import matplotlib.pyplot as plt

# Citirea fisierului CSV
file_path = "lab1/data/surveyDataSience.csv"
df = pd.read_csv(file_path, skiprows=1)

# 1. Distributia respondentilor care programeaza in Python pe categorii de varsta
python_col = "What programming languages do you use on a regular basis? (Select all that apply) - Selected Choice - Python"
age_col = "What is your age (# years)?"
df_python = df[df[python_col].notna()]

distribution_python = df_python[age_col].value_counts()
print("Distributia respondentilor care programeaza in Python pe categorii de varsta:")
print(distribution_python)

plt.figure(figsize=(10, 5))
distribution_python.sort_index().plot(kind="bar", color="blue")
plt.xlabel("Categorie de varsta")
plt.ylabel("Numar de respondenti")
plt.title("Distributia respondentilor care programeaza in Python")
plt.xticks(rotation=45)
plt.show()

# 2. Distributia respondentilor din Romania care programeaza in Python pe categorii de varsta
df_romania_python = df[
    (df["In which country do you currently reside?"] == "Romania")
    & (df[python_col].notna())
]
distribution_romania_python = df_romania_python[age_col].value_counts()

print(
    "Distributia respondentilor din Romania care programeaza in Python pe categorii de varsta:"
)
print(distribution_romania_python)

plt.figure(figsize=(10, 5))
distribution_romania_python.sort_index().plot(kind="bar", color="green")
plt.xlabel("Categorie de varsta")
plt.ylabel("Numar de respondenti")
plt.title("Distributia respondentilor din Romania care programeaza in Python")
plt.xticks(rotation=45)
plt.show()

# 3. Distributia respondentilor femei din Romania care programeaza in Python pe categorii de varsta
df_romania_women_python = df_romania_python[
    df_romania_python["What is your gender? - Selected Choice"] == "Woman"
]
distribution_romania_women_python = df_romania_women_python[age_col].value_counts()

print(
    "Distributia respondentilor femei din Romania care programeaza in Python pe categorii de varsta:"
)
print(distribution_romania_women_python)

plt.figure(figsize=(10, 5))
distribution_romania_women_python.sort_index().plot(kind="bar", color="red")
plt.xlabel("Categorie de varsta")
plt.ylabel("Numar de respondenti")
plt.title("Distributia respondentilor femei din Romania care programeaza in Python")
plt.xticks(rotation=45)
plt.show()

# 4. Identificarea outlierilor in functie de vechimea in programare
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

# Eliminam valorile lipsa pentru analiza
experience_values = df["Years of Programming Experience"].dropna()

# Calculam Q1 si Q3 pentru boxplot
Q1 = np.percentile(experience_values, 25)
Q3 = np.percentile(experience_values, 75)
IQR = Q3 - Q1

# Determinam outlierii
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR
outliers = experience_values[
    (experience_values < lower_bound) | (experience_values > upper_bound)
]

print("Respondentii outlieri in functie de vechimea in programare:")
print(outliers)

# Boxplot pentru identificarea outlierilor
plt.figure(figsize=(8, 5))
plt.boxplot(experience_values, vert=False)
plt.xlabel("Ani de experienta in programare")
plt.title(
    "Boxplot - Distributia experientei in programare si identificarea outlierilor"
)
plt.show()

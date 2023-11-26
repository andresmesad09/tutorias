def contador_sura(letra_inicio, letra_fin, numero_letras):
    # ----
    # Get the list of all words in file
    # ----
    with open('./RPY1_diccionario.txt', mode='r') as f:
        list_of_words = f.read().split()

    # ----
    # Get matching words
    # ----
    contador = 0
    matching_words = []
    for word in list_of_words:
        if word.lower().startswith(letra_inicio.lower()) and word.lower().endswith(letra_fin.lower()) and len(word) == numero_letras:
            contador+=1
            matching_words.append(word)
    print(f"{contador} palabras coinciden con los criterios")

    # ----
    # Get count of consontats
    # ----
    letters_dictionary = {}
    vowel_list = 'aeiouáéíóú'
    for word in matching_words:
        for letter in word:
            if letter not in vowel_list and letter != letra_inicio.lower() and letter != letra_fin.lower():
                if letter in letters_dictionary:
                    letters_dictionary[letter] += 1
                else:
                    letters_dictionary[letter] = 1
            else:
                continue

    # ----
    # Get the max value of consonants
    # ----
    all_values = letters_dictionary.values()
    max_value = max(all_values)

    # ----
    # Get the consonants where count == max_value
    # ----
    most_repeated = []
    for key, value in letters_dictionary.items():
        if value == max_value:
            most_repeated.append(key)
    print(f"Constantes más repetidas: {','.join(most_repeated)}. (Cada una {max_value} veces)")




if __name__ == "__main__":
    letra_inicio = input("Ingrese la letra de inicio: ")
    letra_fin = input("Ingrese la letra fin: ")
    numero_letras = int(input("Ingrese el número de letras: "))
    contador_sura(letra_inicio, letra_fin, numero_letras)


# Aplicație de Cifrare

## Descriere
Această aplicație implementează doi algoritmi clasici de criptare în fișiere separate:
- **substitution.c**: Un cifru de substituție (Cifru Caesar cu o deplasare fixă de 1).
- **transposition.c**: Un cifru de transpunere (inversează ordinea jumătăților textului).

Fiecare fișier conține logica principală și implementarea algoritmului, funcționând independent.

## Ideile Principale ale Algoritmilor

### Substituție (substitution.c)
- **Concept**: Deplasează fiecare literă din text cu o poziție fixă în alfabet (deplasare = 1).
  - **Criptare**: Fiecare literă se mută înainte (ex. 'A' → 'B', 'Z' → 'A').
  - **Decriptare**: Fiecare literă se mută înapoi (ex. 'B' → 'A', 'A' → 'Z').
- **Detalii**: 
  - Păstrează majusculele și minusculele.
  - Caracterele non-alfabetice (spații, cifre) rămân neschimbate.
- **Exemplu**: "HELLO" → "IFMMP" (criptare) → "HELLO" (decriptare).

### Transpunere (transposition.c)
- **Concept**: Rearanjează caracterele prin împărțirea textului în două jumătăți și inversarea ordinii lor.
  - **Criptare**: A doua jumătate este scrisă prima, urmată de prima jumătate (ex. "HELLO" → "LOHEL").
  - **Decriptare**: Inversează procesul pentru a restabili textul original.
- **Detalii**: 
  - Nu adaugă caractere suplimentare (fără umplutură).
  - Funcționează cu lungimi pare sau impare (mijlocul este calculat cu rotunjire în sus).
- **Exemplu**: "HELLO" → "LOHEL" (criptare) → "HELLO" (decriptare).

## Exemple de Propoziții Criptate și Decriptate

### Substituție
1. **Propoziție**: "Aceasta este tema SC"
   - **Criptată**: "Bdfbtub ftuf ufnb TD"
   - **Decriptată**: "Aceasta este tema SC"
2. **Propoziție**: "ALGORITHM"
   - **Criptată**: "BMHPSJUIN"
   - **Decriptată**: "ALGORITHM"
3. **Propoziție**: "CRYPTOGRAPHY"
   - **Criptată**: "DSZQUPHSBQIZ"
   - **Decriptată**: "CRYPTOGRAPHY"

### Transpunere
1. **Propoziție**: "Aceasta este tema SC"
   - **Criptată**: "te tema SCAceasta es"
   - **Decriptată**: "Aceasta este tema SC"
2. **Propoziție**: "ALGORITHM"
   - **Criptată**: "ITHMALGOR"
   - **Decriptată**: "ALGORITHM"
3. **Propoziție**: "CRYPTOGRAPHY"
   - **Criptată**: "GRAPHYCRYPTO"
   - **Decriptată**: "CRYPTOGRAPHY"

# Explicație Utilizare Comenzi

Acest document explică cum să utilizați programele `substitution` și `transposition` cu comenzile specifice din linia de comandă: `./transposition -d input.txt -o output.txt`, `./transposition -e input.txt -o output.txt`, `./substitution -d input.txt -o output.txt` și `./substitution -e input.txt -o output.txt`. Aceste comenzi vă permit să criptați și să decriptați fișiere text folosind doua cifruri diferiți implementați în C.

## Comenzi și Utilizarea Lor

Mai jos sunt cele patru comenzi și ce fac ele:

- **`./transposition -d input.txt -o output.txt`**:
  - Rulează programul `transposition` pentru a decripta textul din `input.txt` folosind un cifru de transpunere (inversează ordinea jumătăților textului) și scrie rezultatul decriptat în `output.txt`.

- **`./transposition -e input.txt -o output.txt`**:
  - Rulează programul `transposition` pentru a cripta textul din `input.txt` prin împărțirea lui în două jumătăți și inversarea ordinii lor, apoi scrie rezultatul criptat în `output.txt`.

- **`./substitution -d input.txt -o output.txt`**:
  - Rulează programul `substitution` pentru a decripta textul din `input.txt` folosind un cifru de substituție (Cifru Caesar cu deplasare 1), deplasând literele înapoi cu o poziție, și scrie rezultatul în `output.txt`.

- **`./substitution -e input.txt -o output.txt`**:
  - Rulează programul `substitution` pentru a cripta textul din `input.txt` prin deplasarea fiecărei litere înainte cu o poziție în alfabet, apoi scrie rezultatul criptat în `output.txt`.

## Ce Înseamnă Fiecare Argument

Fiecare parte a acestor comenzi are un rol specific:
- **`./transposition` sau `./substitution`**:
  - Numele programului executabil. `./transposition` folosește un cifru de transpunere, iar `./substitution` folosește un cifru de substituție. `./` indică terminalului să ruleze programul din directorul curent.
- **`-e`**:
  - Indicatorul de "criptare". Îi spune programului să aplice cifrul pentru a amesteca textul din fișierul de intrare.
- **`-d`**:
  - Indicatorul de "decriptare". Îi spune programului să inverseze cifrul și să recupereze textul original din fișierul de intrare.
- **`input.txt`**:
  - Fișierul de intrare care conține textul pe care doriți să îl criptați sau decriptați. Poate fi orice nume de fișier, dar `input.txt` este folosit aici ca exemplu.
- **`-o output.txt`**:
  - Indicatorul `-o` înseamnă "ieșire în," iar `output.txt` este fișierul în care programul salvează rezultatul. `-o` trebuie urmat de numele fișierului de ieșire, și puteți alege orice nume pentru acesta.

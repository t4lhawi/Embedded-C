# **Sommaire :**

- **[Introduction aux Systèmes Embarqués](#1-introduction-aux-systèmes-embarqués)**
   - **[Architecture Générale](#architecture-générale)**
   -  **[Caractéristiques d’un Système Embarqué](#caractéristiques-dun-système-embarqué)**
   -  **[Cycle de Développement](#cycle-de-développement)**
   -  **[Domaines d’Application](#domaines-dapplication)**


- **[Manipulation des Bits](#2-manipulation-des-bits)**
   - **[Opérations bit à bit (bitwise)](#opérations-bit-à-bit-bitwise)**
   - **[Opérations courantes sur un bit précis](#opérations-courantes-sur-un-bit-précis)**
   - **[Décalages de bits](#décalages-de-bits)**
   - **[Masques de bits (bit masks)](#masques-de-bits-bit-masks)**
- **[Microcontrôleur PIC18F](#3-microcontrôleur-pic18f)**
   - **[Architecture du Microcontrôleur](#architecture-du-microcontrôleur-pic18f45k22)**
   - **[Pins du Microcontrôleur](#pins-du-microcontrôleur-pic18f45k22)**
- **[Ports d’Entrée/Sortie (E/S)](#4-ports-dentréesortie-es)**
   - **[Registres de Contrôle](#registres-de-contrôle)**
<!--
- **[Gestion des Interruptions](#5-gestion-des-interruptions)**
- **[Gestion des Timers](#6-gestion-des-timers)**
-->
---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-C" target="_blank">Lien de Programmation en Langage C</a></h3>

---

## **1. Introduction aux Systèmes Embarqués**

Un **système embarqué** est un système électronique et informatique intégré dans un dispositif plus large, dédié à une tâche précise.
Il combine : **microcontrôleur**, **logiciel embarqué**, **interfaces**, **capteurs** et **actionneurs**.

![embededd](https://github.com/user-attachments/assets/f6afe0d5-a655-4da9-972d-964ff238b188)


- ### **Architecture Générale**
   - **Microcontrôleur / Microprocesseur :**
      - Unité centrale d’exécution (CPU)
      - Utilise mémoire **RAM**, **Flash**, **EEPROM**
   
   - **Mémoire :**
      - Programme (Flash)
      - Données (RAM)
      - Stockage non volatile (EEPROM)
   
   - **Interfaces d’E/S :**
      - GPIO, ADC, DAC
      - UART, SPI, I2C
      - Timers, PWM
   
   - **Capteurs & Actionneurs :**
      - **Capteurs :** température, lumière, mouvement…
      - **Actionneurs :** moteurs, relais, écrans, LEDs…


- ### **Caractéristiques d’un Système Embarqué**

   * **Temps réel** : respecter des délais stricts
   * **Contraintes de ressources** : mémoire limitée, faible consommation
   * **Fiabilité & robustesse** : fonctionnement continu
   * **Optimisation** : code compact, énergie faible
   * **Autonomie** : batterie, capteurs intégrés


- ### **Cycle de Développement**

   - **Analyse du besoin**
   - **Conception (hardware + software)**
   - **Programmation (C, C++, assembleur, RTOS)**
   - **Tests & validation (unitaires, temps réel, consommation)**
   - **Déploiement**
   - **Maintenance / mises à jour**


- ### **Domaines d’Application**

   * Automobile (ESP, ABS, ECU)
   * Aéronautique
   * Domotique et IoT
   * Robotique
   * Médical
   * Télécommunications
   * Industrie 4.0

---

## **2. Manipulation des Bits**

- ### **Opérations bit à bit (bitwise)**

| Opération          | Symbole | Code             | Description                                                                 |
| ------------------ | ------- | ---------------- | --------------------------------------------------------------------------- |
| **AND bit à bit**  | `&`     | `a = x & y`      | Compare bit par bit. Le résultat vaut **1 seulement si les deux bits = 1**. |
| **OR bit à bit**   | `\|`    | `a = x \| y`     | Compare bit par bit. Le résultat vaut **1 si au moins un bit = 1**.         |
| **XOR bit à bit**  | `^`     | `a = x ^ y`      | Résultat vaut **1 si les bits sont différents**.                            |
| **NOT (négation)** | `~`     | `a = ~x`         | Inverse tous les bits (0→1, 1→0).                                           |


- ### **Opérations courantes sur un bit précis**

| Opération                     | Code                       | Description                       |
| ----------------------------- | -------------------------- | --------------------------------- |
| **Mettre un bit à 1**         | `x \|= (1 << n)`          | Active le bit *n*.                |
| **Mettre un bit à 0**         | `x &= ~(1 << n)`          | Désactive le bit *n*.             |
| **Basculer un bit (toggle)**  | `x ^= (1 << n)`           | Change l’état du bit : 0→1 / 1→0. |
| **Tester un bit**             | `(x >> n) & 1`             | Extrait l’état du bit (0 ou 1).   |
| **Lire un bit**               | `if (x & (1 << n))`        | Vrai si le bit *n* vaut 1.        |
| **Copier la valeur d’un bit** | `bit = (x & (1 << n)) != 0` | Récupère la valeur du bit.        |


- ### **Décalages de bits**

| Opération             | Symbole | Code     | Description                                             |
| --------------------- | ------- | -------- | ------------------------------------------------- |
| **Décalage à gauche** | `<<`    | `x << 1` | Multiplie par 2 (décale les bits vers la gauche). |
| **Décalage à droite** | `>>`    | `x >> 1` | Divise par 2 (décale vers la droite).             |


- ### **Masques de bits (bit masks)**

| Opération                          | Code             | Description                                  |
| ---------------------------------- | ---------------- | ------------------------------------- |
| **Créer un masque**                | `mask = 1 << n` | Masque avec seulement le bit n actif. |
| **Garder seulement certains bits** | `x & mask`       | Filtre tout sauf les bits du masque.  |
| **Mettre certains bits à 1**       | `x \| mask`      | Force les bits du masque à 1.         |
| **Mettre certains bits à 0**       | `x & ~mask`      | Force les bits du masque à 0.         |


> `|=` → mettre à **1**

> `&=~` → mettre à **0**

> `^=` → **toggle**

> `&` → tester

> `<<` / `>>` → décaler

---

## **3. Microcontrôleur PIC18F**
Le **PIC18F** fait partie de la famille des microcontrôleurs 8 bits de Microchip, conçus pour les systèmes embarqués nécessitant **performance**, **faible consommation**, et **contrôle bas niveau**.


- ### **Architecture du Microcontrôleur PIC18F45K22**
![arch_pic](https://github.com/user-attachments/assets/7c2701f0-caba-4d97-b3a2-a83eb048764c)


Il repose sur deux caractéristiques clés :

**1. Architecture Harvard (Au Niveau de la Mémoire) :**
  * Séparation entre **mémoire programme** et **mémoire données**
  * Accès parallèles permettant **plus de rapidité**
  * Pipeline matériel pour exécuter certaines instructions en un seul cycle

![arch_mem_pic](https://github.com/user-attachments/assets/7c8c3a9f-9458-432b-9d27-180e6de747bd)


**2. Architecture RISC (Au Niveau du Processeur) :**
  * Ensemble d’instructions réduit, simple et optimisé
  * **Exécution rapide** : la majorité des instructions en **1 cycle**
  * Idéal pour le contrôle temps réel et les applications industrielles


> **Le PIC18F se distingue également par :**
  > - Des **ports d’E/S configurables** (digital/analogique)
  > - Une gestion avancée des **interruptions**
  > - Plusieurs **Timers 8/16 bits**
  > - Interfaces intégrées : **UART, SPI, I²C, PWM**
  > - Convertisseur **ADC 10 ou 12 bits** selon modèle


- ### **Pins du Microcontrôleur PIC18F45K22**

![pic18f](https://github.com/user-attachments/assets/351a6a3f-6c42-4449-994a-32bdab107143)

Voici un tableau clair regroupant les broches essentielles :

| **Pin** | **Nom**          | **Fonction principale**   |
| ------- | ---------------- | ------------------------- |
| 1       | MCLR / Vpp / RE3 | Reset + programmation     |
| 2       | RA0 / AN0        | E/S digitale + ADC        |
| 3       | RA1 / AN1        | E/S digitale + ADC        |
| 4       | RA2 / AN2        | E/S digitale + ADC        |
| 5       | RA3 / AN3        | E/S digitale + ADC        |
| 6       | RA4              | E/S digitale (open-drain) |
| 7       | RA5 / AN4 / SS   | ADC + SPI Slave Select    |
| 8       | RE0 / AN5        | ADC                       |
| 9       | RE1 / AN6        | ADC                       |
| 10      | RE2 / AN7        | ADC                       |
| 11      | Vdd              | Alimentation +5V          |
| 12      | Vss              | Masse                     |
| 13      | RA7              | Horloge externe (OSC1)    |
| 14      | RA6              | Horloge externe (OSC2)    |
| 15      | RC0              | Timer                     |
| 16      | RC1 / CCP2       | PWM                       |
| 17      | RC2 / CCP1       | PWM                       |
| 18      | RC3 / SCL / SCK  | I²C / SPI Clock           |
| 19      | RD0              | E/S digitale              |
| 20      | RD1              | E/S digitale              |
| 21      | RD2              | E/S digitale              |
| 22      | RD3              | E/S digitale              |
| 23      | RC4 / SDA / SDI  | I²C / SPI data            |
| 24      | RC5 / SDO        | SPI                       |
| 25      | RC6 / TX         | UART Transmission         |
| 26      | RC7 / RX         | UART Réception            |
| 27      | RD4              | E/S digitale              |
| 28      | RD5              | E/S digitale              |
| 29      | RD6              | E/S digitale              |
| 30      | RD7              | E/S digitale              |
| 31      | Vss              | Masse                     |
| 32      | Vdd              | Alimentation              |
| 33      | RB0 / INT0       | Interruption externe      |
| 34      | RB1 / INT1       | Interruption              |
| 35      | RB2 / INT2       | Interruption              |
| 36      | RB3 / CCP2       | PWM / Capture             |
| 37      | RB4              | E/S digitale              |
| 38      | RB5              | E/S digitale              |
| 39      | RB6 / PGC        | Programmation ICSP        |
| 40      | RB7 / PGD        | Programmation ICSP        |





> **ADC = “Analog Digital Converter”**
> - Il sert à **convertir une tension analogique** (0 à 5 V) en une **valeur numérique** (0 à 1023 pour un ADC 10 bits).



> **PGC = “Program Clock (Horloge de programmation)”**
> - Donne le timing

> **PGD = “Program Data (Données de programmation)”**
   > - Transporte les valeurs 0/1 pour programmer la mémoire Flash

> **Rxx = “Registres / Pins (RA0, RB5, RC6, etc.)”**
> * **R = Register (PORT)**
> * **A/B/C/D/E = le port**
> * **numéro = le bit/pin**


> **CCP2 = “Capture / Compare / PWM”**
> - **Capture :** Mesurer la durée d’un signal, une fréquence…
> - **Compare :** Déclencher un événement à un moment précis.
> - **PWM :** Générer un signal PWM (moteurs, servos, LED dimming…)


> **MCLR = “Master Clear (Broche Reset)**
> * Réinitialiser (redémarrer) le PIC
> * Activer le mode programmation (Vpp ≈ 12 V)
> * Utilisé par Pickit/ICD

---

## **4. Ports d’Entrée/Sortie (E/S)**

- ### Registres de Contrôle

| Registre    | Fonction                                         | Configuration                                    |
| ----------- | ------------------------------------------------ | ------------------------------------------------ |
| **PORTx**   | Lecture/Écriture logique des broches             | Entrée / Sortie                                  |
| **LATx**    | Registre tampon (Latch) pour une écriture stable | Sortie uniquement                                |
| **TRISx**   | Direction du Port                                | 1 = Entrée<br>0 = Sortie                         |
| **ANSELx**  | Sélection du Mode Analogique ou Numérique        | 1 = Entrée Analogique<br>0 = Numérique (Digital) |
| **SLRCONx** | Contrôle du Slew Rate (réduction des EMI)        | Sortie                                           |


> Une broche configurée avec ANSELx = 1 est forcément une entrée analogique → TRISx doit être à 1.
Pour toute entrée/sortie digitale, ANSELx doit être à 0.





- ### **PORT A :**

| Nom de la broche                            | Fonction | TRIS | ANSEL | Type broche | Type buffer | Description                                             |
| ------------------------------------------- | -------- | ---- | ----- | ----------- | ----------- | ------------------------------------------------------- |
| **RA0 / C12IN0- / AN0**                     | RA0      | 0    | 0     | O           | DIG         | Sortie LATA<0>, non affectée par l’entrée analogique    |
|                                             |          | 1    | 0     | I           | TTL         | Entrée PORTA<0>, désactivée si analogique activé        |
|                                             | C12IN0-  | 1    | 1     | I           | AN          | Entrée inverse des comparateurs C1 et C2                |
|                                             | AN0      | 1    | 1     | I           | AN          | Entrée analogique 0                                     |
| **RA1 / C12IN1- / AN1**                     | RA1      | 0    | 0     | O           | DIG         | Sortie LATA<1>, non affectée par l’entrée analogique    |
|                                             |          | 1    | 0     | I           | TTL         | Entrée PORTA<1>, désactivée si analogique activé        |
|                                             | C12IN1-  | 1    | 1     | I           | AN          | Entrée inverse des comparateurs C1 et C2                |
|                                             | AN1      | 1    | 1     | I           | AN          | Entrée analogique 1                                     |
| **RA2 / C2IN+ / AN2 / DACOUT / VREF-**      | RA2      | 0    | 0     | O           | DIG         | Sortie LATA<2>, désactivée si DACOUT activé             |
|                                             |          | 1    | 0     | I           | TTL         | Entrée PORTA<2>, désactivée si analogique ou DAC activé |
|                                             | C2IN+    | 1    | 1     | I           | AN          | Entrée non-inverse du comparateur C2                    |
|                                             | AN2      | 1    | 1     | I           | AN          | Entrée analogique 2                                     |
|                                             | DACOUT   | x    | 1     | O           | AN          | Sortie de référence DAC                                 |
|                                             | VREF-    | 1    | 1     | I           | AN          | Référence basse ADC                                     |
| **RA3 / C1IN+ / AN3 / VREF+**               | RA3      | 0    | 0     | O           | DIG         | Sortie LATA<3>, non affectée par l’analogique           |
|                                             |          | 1    | 0     | I           | TTL         | Entrée PORTA<3>, désactivée si analogique activé        |
|                                             | C1IN+    | 1    | 1     | I           | AN          | Entrée non-inverse du comparateur C1                    |
|                                             | AN3      | 1    | 1     | I           | AN          | Entrée analogique 3                                     |
|                                             | VREF+    | 1    | 1     | I           | AN          | Référence haute ADC                                     |
| **RA4 / CCP5 / C1OUT / SRQ / T0CKI**        | RA4      | 0    | —     | O           | DIG         | Sortie LATA<4>                                          |
|                                             |          | 1    | —     | I           | ST          | Entrée PORTA<4>, configuration par défaut au reset      |
|                                             | CCP5     | 0    | —     | O           | DIG         | Sortie Capture/Compare/PWM 5                            |
|                                             |          | 1    | —     | I           | ST          | Entrée Capture 5 / Compare 5 / PWM 5                    |
|                                             | C1OUT    | 0    | —     | O           | DIG         | Sortie comparateur C1                                   |
|                                             | SRQ      | 0    | —     | O           | DIG         | Sortie latch SR (prioritaire)                           |
|                                             | T0CKI    | 1    | —     | I           | ST          | Entrée horloge externe Timer0                           |
| **RA5 / C2OUT / SRNQ / SS1 / HLVDIN / AN4** | RA5      | 0    | 0     | O           | DIG         | Sortie LATA<5>, non affectée par l’analogique           |
|                                             |          | 1    | 0     | I           | TTL         | Entrée PORTA<5>, désactivée si analogique activé        |
|                                             | C2OUT    | 0    | 0     | O           | DIG         | Sortie comparateur C2                                   |
|                                             | SRNQ     | 0    | 0     | O           | DIG         | Sortie latch SR                                         |
|                                             | SS1      | 1    | 0     | I           | TTL         | Sélection esclave SPI (MSSP1)                           |
|                                             | HLVDIN   | 1    | 1     | I           | AN          | Entrée détection haute/basse tension                    |
|                                             | AN4      | 1    | 1     | I           | AN          | Entrée analogique 4                                     |
| **RA6 / CLKO / OSC2**                       | RA6      | 0    | —     | O           | DIG         | Sortie LATA<6> (INTOSC, CLKO désactivé)                 |
|                                             |          | 1    | —     | I           | TTL         | Entrée PORTA<6> (INTOSC)                                |
|                                             | CLKO     | x    | —     | O           | DIG         | Sortie CLKO = Fosc/4 (mode RC)                          |
|                                             | OSC2     | x    | —     | O           | XTAL        | Sortie oscillateur (quartz/résonateur)                  |
| **RA7 / CLKI / OSC1**                       | RA7      | 0    | —     | O           | DIG         | Sortie LATA<7>, désactivée en mode oscillateur externe  |
|                                             |          | 1    | —     | I           | TTL         | Entrée PORTA<7>, désactivée en mode oscillateur externe |
|                                             | CLKI     | x    | —     | I           | AN          | Entrée horloge externe                                  |
|                                             | OSC1     | x    | —     | I           | XTAL        | Entrée oscillateur (quartz ou source externe)           |


> * **RA3, RA5** : limitations selon fonctions analogiques
> * **RA6, RA7** : réservées à l’oscillateur
> * **ANSEL = 1 → PORT désactivé**
> * Toujours écrire avec **LATx**, lire avec **PORTx**





| **PORT**   | **Mode Analogique / Digital**                 | **Direction (Entrée / Sortie)**         | **Lecture de l’état** | **Écriture sur la sortie** | **Utilisation principale**           |
| ---------- | --------------------------------------------- | --------------------------------------- | --------------------- | -------------------------- | ------------------------------------ |
| **PORT A** | `ANSELA` : <br>0 = Digital <br>1 = Analogique | `TRISA` : <br>1 = Entrée <br>0 = Sortie | `PORTA`               | `LATA`                     | ADC (AN0–AN4), digital I/O           |
| **PORT B** | Principalement Digital <br>(selon modèles)    | `TRISB`                                 | `PORTB`               | `LATB`                     | Interruptions (INT0/1/2), E/S        |
| **PORT C** | Digital (UART, SPI, I2C)                      | `TRISC`                                 | `PORTC`               | `LATC`                     | Communications : UART, I²C, SPI, PWM |
| **PORT D** | Digital                                       | `TRISD`                                 | `PORTD`               | `LATD`                     | E/S générales, LCD, bus parallèle    |
| **PORTE**  | `ANSELE` : <br>0 = Digital <br>1 = Analogique | `TRISE`                                 | `PORTE`               | `LATE`                     | ADC (AN5–AN7), contrôle mémoire      |



<!--
---

## **5. Gestion des Interruptions**

Chaque périphérique du PIC18F est contrôlé par des **registres** :

* `TRISx` → définit la direction (entrée/sortie).
* `PORTx` → lit les niveaux logiques.
* `LATx`  → écrit sur les sorties.

- **Opérations sur les bits :**

```c
REG |= (1 << n)   // Met le bit n à 1
REG &= ~(1 << n)  // Met le bit n à 0
REG ^= (1 << n)   // Inverse le bit n
if (REG & (1 << n)) { ... } // Teste le bit n
```

---

## **6. Gestion des Timers**

Le PIC18F contient plusieurs zones mémoire :

* **Programme (Flash)** → contient le code C compilé.
* **RAM (Données)** → variables temporaires.
* **EEPROM** → données conservées après coupure d’alimentation.

Les périphériques sont mappés en mémoire, accessibles via des **pointeurs volatiles**.

```c
#define REGISTRE (*(volatile uint8_t*)0xF80)
```
-->
---

<h3 align="center"> 🧑🏻‍💻 | Made By : <a href="https://github.com/t4lhawi" target="_blank">Mohamed Talhaoui</a></h3>

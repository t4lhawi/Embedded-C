# **Sommaire :**

- **[Introduction aux Systèmes Embarqués](#1-introduction-aux-systèmes-embarqués)**
   - **[Architecture Générale](#architecture-générale)**
   -  **[Caractéristiques d’un Système Embarqué](#caractéristiques-dun-système-embarqué)**
   -  **[Cycle de Développement](#cycle-de-développement)**
   -  **[Domaines d’Application](#domaines-dapplication)**


- **[Manipulation des Bits](#2-manipulation-des-bits)**
   - **[Représentation Binaire d’un Octet](#représentation-binaire-dun-octet-char-)**
   - **[Opérations bit à bit (bitwise)](#opérations-bit-à-bit-bitwise)**
   - **[Opérations courantes sur un bit précis](#opérations-courantes-sur-un-bit-précis)**
   - **[Décalages de bits](#décalages-de-bits)**
   - **[Rotation des bits](#rotations-de-bits)**
   - **[Masques de bits (bit masks)](#masques-de-bits-bit-masks)**
- **[Microcontrôleur PIC18F](#3-microcontrôleur-pic18f)**
   - **[Architecture du Microcontrôleur](#architecture-du-microcontrôleur-pic18f45k22)**
   - **[Pins du Microcontrôleur](#pins-du-microcontrôleur-pic18f45k22)**
- **[Ports d’Entrée/Sortie (E/S)](#4-ports-dentréesortie-es)**
   - **[Registres de Contrôle](#registres-de-contrôle)**
   - **[Registres associés au PORTA](#registres-associés-au-porta)**
   - **[Registres associés au PORTB](#registres-associés-au-portb)**
   - **[Registres associés au PORTC](#registres-associés-au-portc)**
   - **[Registres associés au PORTD](#registres-associés-au-portd)**
   - **[Registres associés au PORTE](#registres-associés-au-porte)**
<!--
- **[Gestion des Interruptions](#5-gestion-des-interruptions)**
- **[Gestion des Timers](#6-gestion-des-timers)**
-->
---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-C" target="_blank">Lien de Programmation en C</a></h3>

---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-Cpp" target="_blank">Lien de Programmation en C++</a></h3>

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

- ### Représentation Binaire d’un Octet (char) :
Un type `char` est codé sur 8 bits, numérotés de b0 à b7.
 b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0 |
 -- | -- | -- | -- | -- | -- | -- | -- |
 **MSB** |  |  |  |  |  |  | **LSB** |

> - `LSB` : bit de poids Faible
> - `MSB` : bit de poids Fort
- ### **Opérations bit à bit (bitwise)**

| Opération          | Symbole | Code             | Description                                                                 |
| ------------------ | ------- | ---------------- | --------------------------------------------------------------------------- |
| **AND bit à bit**  | `&`     | `a = x & y`      | Compare bit par bit. Le résultat vaut **1 seulement si les deux bits = 1**. |
| **OR bit à bit**   | `\|`    | `a = x \| y`     | Compare bit par bit. Le résultat vaut **1 si au moins un bit = 1**.         |
| **XOR bit à bit**  | `^`     | `a = x ^ y`      | Résultat vaut **1 si les bits sont différents**.                            |
| **NOT (négation)** | `~`     | `a = ~x`         | Inverse tous les bits (0→1, 1→0).                                           |


- ### **Opérations courantes sur un bit précis**

| Opération                        | Code                        | Description                       |
| -------------------------------- | --------------------------- | --------------------------------- |
| **Mettre un bit à 1 (SET)**      | `x \|= (1 << n)`            | Active le bit *n*.                |
| **Mettre un bit à 0 (CLEAR)**    | `x &= ~(1 << n)`            | Désactive le bit *n*.             |
| **Inversion d’un bit (TOGGLE)**  | `x ^= (1 << n)`             | Complémente le bit n : 0 ↔ 1.     |
| **Extraction d’un bit**          | `(x >> n) & 1`              | Extrait l’état du bit (0 ou 1).   |
| **Test logique d’un bit (TEST)** | `if (x & (1 << n))`         | Vrai si le bit *n* vaut 1.        |
| **Copier la valeur d’un bit**    | `bit = (x & (1 << n)) != 0` | Copie la valeur du bit n dans une variable.  |
| **Échange de deux bits (SWAP)**  | `char bi = (x >> i) & 1;`<br> `char bj = (x >> j) & 1;`<br> `x = (x & ~((1 << i) \| (1 << j))) \| (bi << j) \| (bj << i);` | Échange les valeurs des bits *i* et *j*. |




- ### **Décalages de bits**

| Opération             | Symbole | Code     | Description                                                                          |
| --------------------- | ------- | -------- | ------------------------------------------------------------------------------------ |
| **Décalage à Gauche** | `<<`    | `x << n` | Décale les bits vers la gauche (≈ $`x \times 2^{n}`$).                               |
| **Décalage à Droite** | `>>`    | `x >> n` | Décale les bits vers la droite (≈ $`\left\lfloor \dfrac{x}{2^{n}} \right\rfloor`$).  |



- ### **Rotations de bits**

| Opération             | Code                         | Description                                                            |
| --------------------- | ---------------------------- | ---------------------------------------------------------------------- |
| **Rotation à Gauche** | `(x << n) \| (x >> (8 - n))` | Décalage circulaire vers la gauche (valeur conservée modulo $`2^8`$)   |
| **Rotation à Droite** | `(x >> n) \| (x << (8 - n))` | Décalage circulaire vers la droite (valeur conservée modulo $`2^8`$)   |

> - Les rotations conservent tous les bits, contrairement aux décalages.
> - Pour un `char`, on considère **8 bits** (adapter 8 selon la taille du type).

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

![pic18f](https://github.com/user-attachments/assets/f27b1d27-621b-4148-b83b-737ff575455a)


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
| 31      | Vss              | Masse (-)                 |
| 32      | Vdd              | Alimentation (+)          |
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

> **CCP = “Capture / Compare / PWM”**
> - **Capture :** Mesurer la durée d’un signal, une fréquence…
> - **Compare :** Déclencher un événement à un moment précis.
> - **PWM :** Générer un signal PWM (moteurs, servos, LED dimming…)


> **MCLR = “Master Clear (Broche Reset)”**
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

> - Une broche configurée avec `ANSELx = 1` est forcément une entrée analogique → `TRISx` doit être à 1.
> - Pour toute entrée/sortie digitale, `ANSELx` doit être à 0.


- ### Registres associés au PORTA

<table>
  <thead>
    <tr>
      <th>Nom</th>
      <th>Bit 7</th>
      <th>Bit 6</th>
      <th>Bit 5</th>
      <th>Bit 4</th>
      <th>Bit 3</th>
      <th>Bit 2</th>
      <th>Bit 1</th>
      <th>Bit 0</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>ANSELA</td>
      <td>—</td>
      <td>—</td>
      <td>ANSA5</td>
      <td>—</td>
      <td>ANSA3</td>
      <td>ANSA2</td>
      <td>ANSA1</td>
      <td>ANSA0</td>
    </tr>
    <tr>
      <td>CM1CON0</td>
      <td>C1ON</td>
      <td>C1OUT</td>
      <td>C1OE</td>
      <td>C1POL</td>
      <td>C1SP</td>
      <td>C1R</td>
      <td colspan="2">C1CH&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td>CM2CON0</td>
      <td>C2ON</td>
      <td>C2OUT</td>
      <td>C2OE</td>
      <td>C2POL</td>
      <td>C2SP</td>
      <td>C2R</td>
      <td colspan="2">C2CH&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td>LATA</td>
      <td>LATA7</td>
      <td>LATA6</td>
      <td>LATA5</td>
      <td>LATA4</td>
      <td>LATA3</td>
      <td>LATA2</td>
      <td>LATA1</td>
      <td>LATA0</td>
    </tr>
    <tr>
      <td>VREFCON1</td>
      <td>DACEN</td>
      <td>DACLPS</td>
      <td>DACOE</td>
      <td>—</td>
      <td colspan="2">DACPSS&lt;1:0&gt;</td>
      <td>—</td>
      <td>DACNSS</td>
    </tr>
    <tr>
      <td>VREFCON2</td>
      <td>—</td>
      <td>—</td>
      <td>—</td>
      <td colspan="5">DACR&lt;4:0&gt;</td>
    </tr>
    <tr>
      <td>HVLDCON</td>
      <td>VDRMAG</td>
      <td>BGVST</td>
      <td>IRVST</td>
      <td>HLVDEN</td>
      <td colspan="4">HLVDL&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td>PORTA</td>
      <td>RA7</td>
      <td>RA6</td>
      <td>RA5</td>
      <td>RA4</td>
      <td>RA3</td>
      <td>RA2</td>
      <td>RA1</td>
      <td>RA0</td>
    </tr>
    <tr>
      <td>SLRCON</td>
      <td>—</td>
      <td>—</td>
      <td>—</td>
      <td>SLRE</td>
      <td>SLRD</td>
      <td>SLRC</td>
      <td>SLRB</td>
      <td>SLRA</td>
    </tr>
    <tr>
      <td>SRCON0</td>
      <td>SRLEN</td>
      <td colspan="3">SRCLK&lt;2:0&gt;</td>
      <td>SRQEN</td>
      <td>SRNQEN</td>
      <td>SRPS</td>
      <td>SRPR</td>
    </tr>
    <tr>
      <td>SSP1CON1</td>
      <td>WCOL</td>
      <td>SSPOV</td>
      <td>SSPEN</td>
      <td>CKP</td>
      <td colspan="4">SSPM&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td>T0CON</td>
      <td>TMR0ON</td>
      <td>T08BIT</td>
      <td>T0CS</td>
      <td>T0SE</td>
      <td>PSA</td>
      <td colspan="3">T0PS&lt;2:0&gt;</td>
    </tr>
    <tr>
      <td>TRISA</td>
      <td>TRISA7</td>
      <td>TRISA6</td>
      <td>TRISA5</td>
      <td>TRISA4</td>
      <td>TRISA3</td>
      <td>TRISA2</td>
      <td>TRISA1</td>
      <td>TRISA0</td>
    </tr>
  </tbody>
</table>


> - — = emplacements non implémentés, lus comme ‘0’.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**

- ### Registres associés au PORTB

<table>
  <thead>
    <tr>
      <th>Nom</th>
      <th>Bit 7</th>
      <th>Bit 6</th>
      <th>Bit 5</th>
      <th>Bit 4</th>
      <th>Bit 3</th>
      <th>Bit 2</th>
      <th>Bit 1</th>
      <th>Bit 0</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>ANSELB</strong></td>
      <td>—</td>
      <td>—</td>
      <td>ANSB5</td>
      <td>ANSB4</td>
      <td>ANSB3</td>
      <td>ANSB2</td>
      <td>ANSB1</td>
      <td>ANSB0</td>
    </tr>
    <tr>
      <td><strong>ECCP2AS</strong></td>
      <td>CCP2ASE</td>
      <td colspan="3">CCP2AS&lt;2:0&gt;</td>
      <td colspan="2">PSS2AC&lt;1:0&gt;</td>
      <td colspan="2">PSS2BD&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CCP2CON</strong></td>
      <td colspan="2">P2M&lt;1:0&gt;</td>
      <td colspan="2">DC2B&lt;1:0&gt;</td>
      <td colspan="4">CCP2M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>ECCP3AS</strong></td>
      <td>CCP3ASE</td>
      <td colspan="3">CCP3AS&lt;2:0&gt;</td>
      <td colspan="2">PSS3AC&lt;1:0&gt;</td>
      <td colspan="2">PSS3BD&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CCP3CON</strong></td>
      <td colspan="2">P3M&lt;1:0&gt;</td>
      <td colspan="2">DC3B&lt;1:0&gt;</td>
      <td colspan="4">CCP3M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>INTCON</strong></td>
      <td>GIE / GIEH</td>
      <td>PEIE / GIEL</td>
      <td>TMR0IE</td>
      <td>INT0IE</td>
      <td>RBIE</td>
      <td>TMR0IF</td>
      <td>INT0IF</td>
      <td>RBIF</td>
    </tr>
    <tr>
      <td><strong>INTCON2</strong></td>
      <td>RBPU</td>
      <td>INTEDG0</td>
      <td>INTEDG1</td>
      <td>INTEDG2</td>
      <td>—</td>
      <td>TMR0IP</td>
      <td>—</td>
      <td>RBIP</td>
    </tr>
    <tr>
      <td><strong>INTCON3</strong></td>
      <td>INT2IP</td>
      <td>INT1IP</td>
      <td>—</td>
      <td>INT2IE</td>
      <td>INT1IE</td>
      <td>—</td>
      <td>INT2IF</td>
      <td>INT1IF</td>
    </tr>
    <tr>
      <td><strong>IOCB</strong></td>
      <td>IOCB7</td>
      <td>IOCB6</td>
      <td>IOCB5</td>
      <td>IOCB4</td>
      <td>—</td>
      <td>—</td>
      <td>—</td>
      <td>—</td>
    </tr>
    <tr>
      <td><strong>LATB</strong></td>
      <td>LATB7</td>
      <td>LATB6</td>
      <td>LATB5</td>
      <td>LATB4</td>
      <td>LATB3</td>
      <td>LATB2</td>
      <td>LATB1</td>
      <td>LATB0</td>
    </tr>
    <tr>
      <td><strong>PORTB</strong></td>
      <td>RB7</td>
      <td>RB6</td>
      <td>RB5</td>
      <td>RB4</td>
      <td>RB3</td>
      <td>RB2</td>
      <td>RB1</td>
      <td>RB0</td>
    </tr>
    <tr>
      <td><strong>SLRCON</strong></td>
      <td>—</td>
      <td>—</td>
      <td>—</td>
      <td>SLRE (1)</td>
      <td>SLRD (1)</td>
      <td>SLRC</td>
      <td>SLRB</td>
      <td>SLRA</td>
    </tr>
    <tr>
      <td><strong>T1GCON</strong></td>
      <td>TMR1GE</td>
      <td>T1GPOL</td>
      <td>T1GTM</td>
      <td>T1GSPM</td>
      <td>T1GGO / ¬DONE</td>
      <td>T1GVAL</td>
      <td colspan="2">T1GSS&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>T3CON</strong></td>
      <td colspan="2">TMR3CS&lt;1:0&gt;</td>
      <td colspan="2">T3CKPS&lt;1:0&gt;</td>
      <td>T3SOSCEN</td>
      <td>¬T3SYNC</td>
      <td>T3RD16</td>
      <td>TMR3ON</td>
    </tr>
    <tr>
      <td><strong>T5CON</strong></td>
      <td>TMR5GE</td>
      <td>T5GPOL</td>
      <td>T5GTM</td>
      <td>T5GSPM</td>
      <td>T5GGO / ¬DONE</td>
      <td>T5GVAL</td>
      <td colspan="2">T5GSS&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>TRISB</strong></td>
      <td>TRISB7</td>
      <td>TRISB6</td>
      <td>TRISB5</td>
      <td>TRISB4</td>
      <td>TRISB3</td>
      <td>TRISB2</td>
      <td>TRISB1</td>
      <td>TRISB0</td>
    </tr>
    <tr>
      <td><strong>WPUB</strong></td>
      <td>WPUB7</td>
      <td>WPUB6</td>
      <td>WPUB5</td>
      <td>WPUB4</td>
      <td>WPUB3</td>
      <td>WPUB2</td>
      <td>WPUB1</td>
      <td>WPUB0</td>
    </tr>
  </tbody>
</table>


> - — = emplacements non implémentés, lus comme ‘0’.
> - Les **bits grisés ne sont pas utilisés pour PORTB**.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**



- ### Registres associés au PORTC

<table>
  <thead>
    <tr>
      <th>Nom</th>
      <th>Bit 7</th>
      <th>Bit 6</th>
      <th>Bit 5</th>
      <th>Bit 4</th>
      <th>Bit 3</th>
      <th>Bit 2</th>
      <th>Bit 1</th>
      <th>Bit 0</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>ANSELC</strong></td>
      <td>ANSC7</td>
      <td>ANSC6</td>
      <td>ANSC5</td>
      <td>ANSC4</td>
      <td>ANSC3</td>
      <td>ANSC2</td>
      <td colspan="2">—</td>
    </tr>
    <tr>
      <td><strong>ECCP1AS</strong></td>
      <td>CCP1ASE</td>
      <td colspan="3">CCP1AS&lt;2:0&gt;</td>
      <td colspan="2">PSS1AC&lt;1:0&gt;</td>
      <td colspan="2">PSS1BD&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CCP1CON</strong></td>
      <td colspan="2">P1M&lt;1:0&gt;</td>
      <td colspan="2">DC1B&lt;1:0&gt;</td>
      <td colspan="4">CCP1M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>ECCP2AS</strong></td>
      <td>CCP2ASE</td>
      <td colspan="3">CCP2AS&lt;2:0&gt;</td>
      <td colspan="2">PSS2AC&lt;1:0&gt;</td>
      <td colspan="2">PSS2BD&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CCP2CON</strong></td>
      <td colspan="2">P2M&lt;1:0&gt;</td>
      <td colspan="2">DC2B&lt;1:0&gt;</td>
      <td colspan="4">CCP2M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CTMUCONH</strong></td>
      <td>CTMUEN</td>
      <td>—</td>
      <td>CTMUSIDL</td>
      <td>TGEN</td>
      <td>EDGEN</td>
      <td>EDGSEQEN</td>
      <td>IDISSEN</td>
      <td>CTTRIG</td>
    </tr>
    <tr>
      <td><strong>LATC</strong></td>
      <td>LATC7</td>
      <td>LATC6</td>
      <td>LATC5</td>
      <td>LATC4</td>
      <td>LATC3</td>
      <td>LATC2</td>
      <td>LATC1</td>
      <td>LATC0</td>
    </tr>
    <tr>
      <td><strong>PORTC</strong></td>
      <td>RC7</td>
      <td>RC6</td>
      <td>RC5</td>
      <td>RC4</td>
      <td>RC3</td>
      <td>RC2</td>
      <td>RC1</td>
      <td>RC0</td>
    </tr>
    <tr>
      <td><strong>RCSTA1</strong></td>
      <td>SPEN</td>
      <td>RX9</td>
      <td>SREN</td>
      <td>CREN</td>
      <td>ADDEN</td>
      <td>FERR</td>
      <td>OERR</td>
      <td>RX9D</td>
    </tr>
    <tr>
      <td><strong>SLRCON</strong></td>
      <td colspan="3">—</td>
      <td>SLRE (1)</td>
      <td>SLRD (1)</td>
      <td>SLRC</td>
      <td>SLRB</td>
      <td>SLRA</td>
    </tr>
    <tr>
      <td><strong>SSP1CON1</strong></td>
      <td>WCOL</td>
      <td>SSPOV</td>
      <td>SSPEN</td>
      <td>CKP</td>
      <td colspan="4">SSPM&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>T1CON</strong></td>
      <td colspan="2">TMR1CS&lt;1:0&gt;</td>
      <td colspan="2">T1CKPS&lt;1:0&gt;</td>
      <td>T1SOSCEN</td>
      <td>¬T1SYNC</td>
      <td>T1RD16</td>
      <td>TMR1ON</td>
    </tr>
    <tr>
      <td><strong>T3CON</strong></td>
      <td colspan="2">TMR3CS&lt;1:0&gt;</td>
      <td colspan="2">T3CKPS&lt;1:0&gt;</td>
      <td>T3SOSCEN</td>
      <td>¬T3SYNC</td>
      <td>T3RD16</td>
      <td>TMR3ON</td>
    </tr>
    <tr>
      <td><strong>T3GCON</strong></td>
      <td>TMR3GE</td>
      <td>T3GPOL</td>
      <td>T3GTM</td>
      <td>T3GSPM</td>
      <td>T3GGO / ¬DONE</td>
      <td>T3GVAL</td>
      <td colspan="2">T3GSS&lt;1:0&gt;</td>
    </tr>
    <tr>
      <td><strong>T5CON</strong></td>
      <td colspan="2">TMR5CS&lt;1:0&gt;</td>
      <td colspan="2">T5CKPS&lt;1:0&gt;</td>
      <td>T5SOSCEN</td>
      <td>¬T5SYNC</td>
      <td>T5RD16</td>
      <td>TMR5ON</td>
    </tr>
    <tr>
      <td><strong>TRISC</strong></td>
      <td>TRISC7</td>
      <td>TRISC6</td>
      <td>TRISC5</td>
      <td>TRISC4</td>
      <td>TRISC3</td>
      <td>TRISC2</td>
      <td>TRISC1</td>
      <td>TRISC0</td>
    </tr>
    <tr>
      <td><strong>TXSTA1</strong></td>
      <td>CSRC</td>
      <td>TX9</td>
      <td>TXEN</td>
      <td>SYNC</td>
      <td>SENDB</td>
      <td>BRGH</td>
      <td>TRMT</td>
      <td>TX9D</td>
    </tr>
  </tbody>
</table>


> - — = **emplacements non implémentés, lus comme ‘0’**.
> - Les **bits grisés ne sont pas utilisés pour PORTC**.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**

- ### Registres associés au PORTD

<table>
  <thead>
    <tr>
      <th>Nom</th>
      <th>Bit 7</th>
      <th>Bit 6</th>
      <th>Bit 5</th>
      <th>Bit 4</th>
      <th>Bit 3</th>
      <th>Bit 2</th>
      <th>Bit 1</th>
      <th>Bit 0</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>ANSELD</strong></td>
      <td>ANSD7</td>
      <td>ANSD6</td>
      <td>ANSD5</td>
      <td>ANSD4</td>
      <td>ANSD3</td>
      <td>ANSD2</td>
      <td>ANSD1</td>
      <td>ANSD0</td>
    </tr>
    <tr>
      <td><strong>BAUDCON2</strong></td>
      <td>ABDOVF</td>
      <td>RCIDL</td>
      <td>DTRXP</td>
      <td>CKTXP</td>
      <td>BRG16</td>
      <td>—</td>
      <td>WUE</td>
      <td>ABDEN</td>
    </tr>
    <tr>
      <td><strong>CCP1CON</strong></td>
      <td colspan="2">P1M&lt;1:0&gt;</td>
      <td colspan="2">DC1B&lt;1:0&gt;</td>
      <td colspan="4">CCP1M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CCP2CON</strong></td>
      <td colspan="2">P2M&lt;1:0&gt;</td>
      <td colspan="2">DC2B&lt;1:0&gt;</td>
      <td colspan="4">CCP2M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>CCP4CON</strong></td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td colspan="2">DC4B&lt;1:0&gt;</td>
      <td colspan="4">CCP4M&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>LATD</strong></td>
      <td>LATD7</td>
      <td>LATD6</td>
      <td>LATD5</td>
      <td>LATD4</td>
      <td>LATD3</td>
      <td>LATD2</td>
      <td>LATD1</td>
      <td>LATD0</td>
    </tr>
    <tr>
      <td><strong>PORTD</strong></td>
      <td>RD7</td>
      <td>RD6</td>
      <td>RD5</td>
      <td>RD4</td>
      <td>RD3</td>
      <td>RD2</td>
      <td>RD1</td>
      <td>RD0</td>
    </tr>
    <tr>
      <td><strong>RCSTA2</strong></td>
      <td>SPEN</td>
      <td>RX9</td>
      <td>SREN</td>
      <td>CREN</td>
      <td>ADDEN</td>
      <td>FERR</td>
      <td>OERR</td>
      <td>RX9D</td>
    </tr>
    <tr>
      <td><strong>SLRCON</strong></td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td>SLRE</td>
      <td>SLRD</td>
      <td>SLRC</td>
      <td>SLRB</td>
      <td>SLRA</td>
    </tr>
    <tr>
      <td><strong>SSP2CON1</strong></td>
      <td>WCOL</td>
      <td>SSPOV</td>
      <td>SSPEN</td>
      <td>CKP</td>
      <td colspan="4">SSPM&lt;3:0&gt;</td>
    </tr>
    <tr>
      <td><strong>TRISD</strong></td>
      <td>TRISD7</td>
      <td>TRISD6</td>
      <td>TRISD5</td>
      <td>TRISD4</td>
      <td>TRISD3</td>
      <td>TRISD2</td>
      <td>TRISD1</td>
      <td>TRISD0</td>
    </tr>

  </tbody>
</table>


> - — = **emplacements non implémentés, lus comme ‘0’**.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**
>    - `n` = bit le plus significatif (à gauche) du champ
>    - `m` = bit le moins significatif (à droite) du champ

- ### Registres associés au PORTE

<table>
  <thead>
    <tr>
      <th>Nom</th>
      <th>Bit 7</th>
      <th>Bit 6</th>
      <th>Bit 5</th>
      <th>Bit 4</th>
      <th>Bit 3</th>
      <th>Bit 2</th>
      <th>Bit 1</th>
      <th>Bit 0</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>ANSELE</strong></td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td>ANSE2</td>
      <td>ANSE1</td>
      <td>ANSE0</td>
    </tr>
    <tr>
      <td><strong>INTCON2</strong></td>
      <td>¬RBPU</td>
      <td>INTEDG0</td>
      <td>INTEDG1</td>
      <td>INTEDG2</td>
      <td>—</td>
      <td>TMR0IP</td>
      <td>—</td>
      <td>RBIP</td>
    </tr>
    <tr>
      <td><strong>LATE</strong></td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td>LATE2</td>
      <td>LATE1</td>
      <td>LATE0</td>
    </tr>
    <tr>
      <td><strong>PORTE</strong></td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td>RE3</td>
      <td>RE2</td>
      <td>RE1</td>
      <td>RE0</td>
    </tr>
    <tr>
      <td><strong>SLRCON</strong></td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td>SLRE</td>
      <td>SLRD</td>
      <td>SLRC</td>
      <td>SLRB</td>
      <td>SLRA</td>
    </tr>
    <tr>
      <td><strong>TRISE</strong></td>
      <td>WPUE3</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
       <td>—</td>
      <td>TRISE2</td>
      <td>TRISE1</td>
      <td>TRISE0</td>
    </tr>

  </tbody>
</table>


> - — = **emplacements non implémentés, lus comme ‘0’**.
> - Les **bits grisés ne sont pas utilisés pour PORTC**.



<!--
---

## **5. Gestion des Interruptions**

---

## **6. Gestion des Timers**

-->
---

<h3 align="center"> 🧑🏻‍💻 | Made By : <a href="https://github.com/t4lhawi" target="_blank">Mohamed Talhaoui</a></h3>

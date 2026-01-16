# **Plan du Contenu :**

- ## **[Introduction aux Systèmes Embarqués](#1-introduction-aux-systèmes-embarqués)**
   - **[Architecture Générale](#architecture-générale)**
   - **[Caractéristiques d’un Système Embarqué](#caractéristiques-dun-système-embarqué)**
   - **[Cycle de Développement](#cycle-de-développement)**
   - **[Domaines d’Application](#domaines-dapplication)**

- ## **[Manipulation des Bits](#2-manipulation-des-bits)**
   - **[Représentation Binaire d’un Octet](#représentation-binaire-dun-octet-char)**
   - **[Opérations Bit à Bit (Bitwise)](#opérations-bit-à-bit-bitwise)**
   - **[Opérations Courantes sur un Bit Précis](#opérations-courantes-sur-un-bit-précis)**
   - **[Décalages de Bits](#décalages-de-bits)**
   - **[Rotation des Bits](#rotations-de-bits)**
   - **[Masques de Bits (Bit masks)](#masques-de-bits-bit-masks)**

- ## **[Microcontrôleur PIC18F](#3-microcontrôleur-pic18f)**
   - **[Architecture du Microcontrôleur](#architecture-du-microcontrôleur-pic18f45k22)**
   - **[Pins du Microcontrôleur](#pins-du-microcontrôleur-pic18f45k22)**

- ## **[Ports d’Entrée/Sortie (E/S)](#4-ports-dentréesortie-es)**
   - **[Registres de Contrôle](#registres-de-contrôle)**
   - **[Registres Associés au PORTA](#registres-associés-au-porta)**
   - **[Registres Associés au PORTB](#registres-associés-au-portb)**
   - **[Registres Associés au PORTC](#registres-associés-au-portc)**
   - **[Registres Associés au PORTD](#registres-associés-au-portd)**
   - **[Registres Associés au PORTE](#registres-associés-au-porte)**

- ## **[Gestion des Interruptions](#5-gestion-des-interruptions)**
   - **[Types des Interruptions](#types-des-interruptions-sources)**
   - **[Mécanisme de Contrôle](#mécanisme-de-contrôle)**
   - **[Priorité des Interruptions](#priorité-des-interruptions)**
   - **[Registres de Gestion d'Interruption](#registres-de-gestion-dinterruption)**

- ## **[Gestion des Timers](#6-gestion-des-timers)**
   - **[Caractéristiques des Timers](#caractéristiques-des-timers)**
   - **[Timer 0 (TMR0)](#timer-0-tmr0)**
   - **[Timers 1, 3 et 5 (TMR1/3/5)](#timer-135-tmr135)**
   - **[Timers 2, 4 et 6 (TMR2/4/6)](#timer-246-tmr246)**

- ## **[Gestion de CAN](#7-gestion-de-can)**
   - **[Étapes de Conversion](#étapes-de-conversion-an)**
   - **[Registres de Contrôle](#registres-de-contrôle-2)**
   - **[Registres Associés](#registres-associés)**
   - **[Fonctionnes Avancé *MikroC*](#fonctionnes-avancé-mikroc)**

- ## **[Gestion de CNA](#8-gestion-de-cna)**
   - **[Étapes de Conversion](#étapes-de-conversion-na)**
   - **[Registres de Contrôle](#registres-de-contrôle-3)**
   - **[Registres Associés](#registres-associés-1)**

- ## **[Gestion de PWM](#9-gestion-de-pwm)**
   - **[Caractéristiques du PWM](#caractéristiques-du-pwm)**
   - **[Étapes de Configuration](#étapes-de-configuration)**
   - **[Registres de Contrôle](#registres-de-contrôle-4)**
   - **[Registres Associés](#registres-associés-2)**
   - **[Fonctionnes Avancé *MikroC*](#fonctionnes-avancé-mikroc-1)**


---

<h3 align="center"><a href="https://ww1.microchip.com/downloads/jp/DeviceDoc/jp547043.pdf" target="_blank">Data Sheet - PIC18(L)F2X/4XK22</a></h3>

---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-C" target="_blank">Programmation en C</a></h3>

---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-Cpp" target="_blank">Programmation en C++</a></h3>

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

- ### Représentation Binaire d’un Octet (`char`)
   Un type `char` est codé sur 8 bits, numérotés de b0 à b7.
   <table>
     <thead>
       <tr>
         <th>b7</th>
         <th>b6</th>
         <th>b5</th>
         <th>b4</th>
         <th>b3</th>
         <th>b2</th>
         <th>b1</th>
         <th>b0</th>
       </tr>
     </thead>
     <tbody>
       <tr>
         <td><strong>MSB</strong></td>
         <td colspan="6"></td>
         <td><strong>LSB</strong></td>
       </tr>
     </tbody>
   </table>
   
   > - `LSB` : bit de poids Faible
   > - `MSB` : bit de poids Fort

- ### **Opérations Bit à Bit (Bitwise)**

   | Opération          | Symbole | Code             | Description                                                                 |
   | ------------------ | ------- | ---------------- | --------------------------------------------------------------------------- |
   | **AND bit à bit**  | `&`     | `a = x & y`      | Compare bit par bit. Le résultat vaut **1 seulement si les deux bits = 1**. |
   | **OR bit à bit**   | `\|`    | `a = x \| y`     | Compare bit par bit. Le résultat vaut **1 si au moins un bit = 1**.         |
   | **XOR bit à bit**  | `^`     | `a = x ^ y`      | Résultat vaut **1 si les bits sont différents**.                            |
   | **NOT (négation)** | `~`     | `a = ~x`         | Inverse tous les bits (0→1, 1→0).                                           |


- ### **Opérations Courantes sur un Bit Précis**

   | Opération                        | Code                        | Description                       |
   | -------------------------------- | --------------------------- | --------------------------------- |
   | **Mettre un bit à 1 (SET)**      | `x \|= (1 << n)`            | Active le bit *n*.                |
   | **Mettre un bit à 0 (CLEAR)**    | `x &= ~(1 << n)`            | Désactive le bit *n*.             |
   | **Inversion d’un bit (TOGGLE)**  | `x ^= (1 << n)`             | Complémente le bit n : 0 ↔ 1.     |
   | **Extraction d’un bit**          | `(x >> n) & 1`              | Extrait l’état du bit (0 ou 1).   |
   | **Test logique d’un bit (TEST)** | `if (x & (1 << n))`         | Vrai si le bit *n* vaut 1.        |
   | **Copier la valeur d’un bit**    | `bit = (x & (1 << n)) != 0` | Copie la valeur du bit n dans une variable.  |
   | **Échange de deux bits (SWAP)**  | `char bi = (x >> i) & 1;`<br> `char bj = (x >> j) & 1;`<br> `x = (x & ~((1 << i) \| (1 << j))) \| (bi << j) \| (bj << i);` | Échange les valeurs des bits *i* et *j*. |




- ### **Décalages de Bits**

   | Opération             | Symbole | Code     | Description                                                                          |
   | --------------------- | ------- | -------- | ------------------------------------------------------------------------------------ |
   | **Décalage à Gauche** | `<<`    | `x << n` | Décale les bits vers la gauche (≈ $`x \times 2^{n}`$).                               |
   | **Décalage à Droite** | `>>`    | `x >> n` | Décale les bits vers la droite (≈ $`\left\lfloor \dfrac{x}{2^{n}} \right\rfloor`$).  |



- ### **Rotations de Bits**

   | Opération             | Code                         | Description                                                            |
   | --------------------- | ---------------------------- | ---------------------------------------------------------------------- |
   | **Rotation à Gauche** | `(x << n) \| (x >> (8 - n))` | Décalage circulaire vers la gauche (valeur conservée modulo $`2^8`$)   |
   | **Rotation à Droite** | `(x >> n) \| (x << (8 - n))` | Décalage circulaire vers la droite (valeur conservée modulo $`2^8`$)   |

   > - Les rotations conservent tous les bits, contrairement aux décalages.
   > - Pour un `char`, on considère **8 bits** (adapter 8 selon la taille du type).

- ### **Masques de Bits (Bit Masks)**

   | Opération                          | Code             | Description                           |
   | ---------------------------------- | ---------------- | ------------------------------------- |
   | **Créer un masque**                | `mask = 1 << n`  | Masque avec seulement le bit n actif. |
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
Le **[PIC18F&sup1;](https://en.wikipedia.org/wiki/PIC_microcontrollers)** fait partie de la famille des microcontrôleurs 8 bits de Microchip, conçus pour les systèmes embarqués nécessitant **performance**, **faible consommation**, et **contrôle bas niveau**.


- ### **Architecture du Microcontrôleur PIC18F45K22**
   ![arch_pic](https://github.com/user-attachments/assets/7c2701f0-caba-4d97-b3a2-a83eb048764c)

   
   - **[Architecture Harvard&sup2;](https://en.wikipedia.org/wiki/Harvard_architecture) (Au Niveau de la Mémoire) :**
      - Séparation entre **mémoire programme** et **mémoire données**
      - Accès parallèles permettant **plus de rapidité**
      - Pipeline matériel pour exécuter certaines instructions en un seul cycle
   
   ![arch_mem_pic](https://github.com/user-attachments/assets/7c8c3a9f-9458-432b-9d27-180e6de747bd)
   
   
   - **[Architecture RISC&sup3;](https://en.wikipedia.org/wiki/Reduced_instruction_set_computer) (Au Niveau du Processeur) :**
      - Ensemble d’instructions réduit, simple et optimisé
      - **Exécution rapide** : la majorité des instructions en **1 cycle**
      - Idéal pour le contrôle temps réel et les applications industrielles


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
   > - **R = Register (PORT)**
   > - **A/B/C/D/E = le port**
   > - **numéro = le bit/pin**
   
   > **CCP = “Capture / Compare / PWM”**
   > - **Capture :** Mesurer la durée d’un signal, une fréquence…
   > - **Compare :** Déclencher un événement à un moment précis.
   > - **PWM :** Générer un signal PWM (moteurs, servos, LED dimming…)
   
   
   > **MCLR = “Master Clear (Broche Reset)”**
   > - Réinitialiser (redémarrer) le PIC
   > - Activer le mode programmation (Vpp ≈ 12 V)
   > - Utilisé par Pickit/ICD

---

## **4. Ports d’Entrée/Sortie (E/S)**

- ### Registres de Contrôle

   | Registre    | Fonction                                             | Configuration                                    |
   | ----------- | ---------------------------------------------------- | ------------------------------------------------ |
   | **PORTx**   | Lecture/Écriture logique réel des broches            | Entrée / Sortie                                  |
   | **LATx**    | Registre tampon (Latch) pour une écriture **Stable** | Sortie Uniquement                                |
   | **TRISx**   | Direction du Port                                    | 1 = Entrée<br>0 = Sortie                         |
   | **ANSELx**  | Sélection du Mode Analogique ou Numérique            | 1 = **Entrée** Analogique<br>0 = Numérique (Digital) |
   | **SLRCONx** | Contrôle du Slew Rate (réduction des EMI)            | Sortie (selon port / MCU)                        |

   > - **Lire** avec `PORTx`, **Écrire** avec `LATx` pour Évite Risque de **Read-Modify-Write (RMW)**
   > - `ANSELx = 1` ⇒ Entrée Analogique ⇒ `TRISx = 1` **Obligatoire !!**
   > - Pour toute E/S Digitale ⇒ `ANSELx = 0`
   > - Manipulation des Sorties **Toujours via `LATx`**


- ### Registres Associés au PORTA

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
         <td><strong>ANSELA</strong></td>
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
         <td><strong>CM1CON0</strong></td>
         <td>C1ON</td>
         <td>C1OUT</td>
         <td>C1OE</td>
         <td>C1POL</td>
         <td>C1SP</td>
         <td>C1R</td>
         <td align="center" colspan="2">C1CH&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CM2CON0</strong></td>
         <td>C2ON</td>
         <td>C2OUT</td>
         <td>C2OE</td>
         <td>C2POL</td>
         <td>C2SP</td>
         <td>C2R</td>
         <td align="center" colspan="2">C2CH&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>LATA</strong></td>
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
         <td><strong>VREFCON1</strong></td>
         <td>DACEN</td>
         <td>DACLPS</td>
         <td>DACOE</td>
         <td>—</td>
         <td align="center" colspan="2">DACPSS&lt;1:0&gt;</td>
         <td>—</td>
         <td>DACNSS</td>
       </tr>
       <tr>
         <td><strong>VREFCON2</strong></td>
         <td>—</td>
         <td>—</td>
         <td>—</td>
         <td align="center" colspan="5">DACR&lt;4:0&gt;</td>
       </tr>
       <tr>
         <td><strong>HVLDCON</strong></td>
         <td>VDRMAG</td>
         <td>BGVST</td>
         <td>IRVST</td>
         <td>HLVDEN</td>
         <td align="center" colspan="4">HLVDL&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>PORTA</strong></td>
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
         <td><strong>SRCON0</strong></td>
         <td>SRLEN</td>
         <td align="center" colspan="3">SRCLK&lt;2:0&gt;</td>
         <td>SRQEN</td>
         <td>SRNQEN</td>
         <td>SRPS</td>
         <td>SRPR</td>
       </tr>
       <tr>
         <td><strong>SSP1CON1</strong></td>
         <td>WCOL</td>
         <td>SSPOV</td>
         <td>SSPEN</td>
         <td>CKP</td>
         <td align="center" colspan="4">SSPM&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>T0CON</strong></td>
         <td>TMR0ON</td>
         <td>T08BIT</td>
         <td>T0CS</td>
         <td>T0SE</td>
         <td>PSA</td>
         <td align="center" colspan="3">T0PS&lt;2:0&gt;</td>
       </tr>
       <tr>
         <td><strong>TRISA</strong></td>
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

- ### Registres Associés au PORTB

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
         <td align="center" colspan="3">CCP2AS&lt;2:0&gt;</td>
         <td align="center" colspan="2">PSS2AC&lt;1:0&gt;</td>
         <td align="center" colspan="2">PSS2BD&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CCP2CON</strong></td>
         <td align="center" colspan="2">P2M&lt;1:0&gt;</td>
         <td align="center" colspan="2">DC2B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP2M&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>ECCP3AS</strong></td>
         <td>CCP3ASE</td>
         <td align="center" colspan="3">CCP3AS&lt;2:0&gt;</td>
         <td align="center" colspan="2">PSS3AC&lt;1:0&gt;</td>
         <td align="center" colspan="2">PSS3BD&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CCP3CON</strong></td>
         <td align="center" colspan="2">P3M&lt;1:0&gt;</td>
         <td align="center" colspan="2">DC3B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP3M&lt;3:0&gt;</td>
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
         <td>SLRE</td>
         <td>SLRD</td>
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
         <td>T1GGO / ¬<span style="text-decoration: overline">DONE</span></td>
         <td>T1GVAL</td>
         <td align="center" colspan="2">T1GSS&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>T3CON</strong></td>
         <td align="center" colspan="2">TMR3CS&lt;1:0&gt;</td>
         <td align="center" colspan="2">T3CKPS&lt;1:0&gt;</td>
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
         <td align="center" colspan="2">T5GSS&lt;1:0&gt;</td>
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



- ### Registres Associés au PORTC

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
         <td>—</td>
          <td>—</td>
       </tr>
       <tr>
         <td><strong>ECCP1AS</strong></td>
         <td>CCP1ASE</td>
         <td align="center" colspan="3">CCP1AS&lt;2:0&gt;</td>
         <td align="center" colspan="2">PSS1AC&lt;1:0&gt;</td>
         <td align="center" colspan="2">PSS1BD&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CCP1CON</strong></td>
         <td align="center" colspan="2">P1M&lt;1:0&gt;</td>
         <td align="center" colspan="2">DC1B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP1M&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>ECCP2AS</strong></td>
         <td>CCP2ASE</td>
         <td align="center" colspan="3">CCP2AS&lt;2:0&gt;</td>
         <td align="center" colspan="2">PSS2AC&lt;1:0&gt;</td>
         <td align="center" colspan="2">PSS2BD&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CCP2CON</strong></td>
         <td align="center" colspan="2">P2M&lt;1:0&gt;</td>
         <td align="center" colspan="2">DC2B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP2M&lt;3:0&gt;</td>
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
         <td><strong>SSP1CON1</strong></td>
         <td>WCOL</td>
         <td>SSPOV</td>
         <td>SSPEN</td>
         <td>CKP</td>
         <td align="center" colspan="4">SSPM&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>T1CON</strong></td>
         <td align="center" colspan="2">TMR1CS&lt;1:0&gt;</td>
         <td align="center" colspan="2">T1CKPS&lt;1:0&gt;</td>
         <td>T1SOSCEN</td>
         <td>¬T1SYNC</td>
         <td>T1RD16</td>
         <td>TMR1ON</td>
       </tr>
       <tr>
         <td><strong>T3CON</strong></td>
         <td align="center" colspan="2">TMR3CS&lt;1:0&gt;</td>
         <td align="center" colspan="2">T3CKPS&lt;1:0&gt;</td>
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
         <td align="center" colspan="2">T3GSS&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>T5CON</strong></td>
         <td align="center" colspan="2">TMR5CS&lt;1:0&gt;</td>
         <td align="center" colspan="2">T5CKPS&lt;1:0&gt;</td>
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

- ### Registres Associés au PORTD

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
         <td align="center" colspan="2">P1M&lt;1:0&gt;</td>
         <td align="center" colspan="2">DC1B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP1M&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CCP2CON</strong></td>
         <td align="center" colspan="2">P2M&lt;1:0&gt;</td>
         <td align="center" colspan="2">DC2B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP2M&lt;3:0&gt;</td>
       </tr>
       <tr>
         <td><strong>CCP4CON</strong></td>
          <td>—</td>
          <td>—</td>
          <td>—</td>
         <td align="center" colspan="2">DC4B&lt;1:0&gt;</td>
         <td align="center" colspan="4">CCP4M&lt;3:0&gt;</td>
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
         <td align="center" colspan="4">SSPM&lt;3:0&gt;</td>
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

- ### Registres Associés au PORTE

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

---

## **5. Gestion des Interruptions**
Une interruption est un événement qui provoque l'**arrêt immédiat du programme principal** pour exécuter une fonction spécifique appelée **ISR** (Interrupt Service Routine). Une fois le traitement terminé, le microcontrôleur reprend l'exécution du programme principal exactement là où il s'était arrêté.

- ### Types des Interruptions (Sources)

   - #### **Interruptions Externes**

      | Source | Broche  | Description                         |
      | ------ | ------- | ----------------------------------- |
      | INT0   | `RB0`     | Interruption sur front externe      |
      | INT1   | `RB1`     | Interruption sur front externe      |
      | INT2   | `RB2`     | Interruption sur front externe      |
      | RBIF   | `RB4` à `RB7` | Changement d’état des broches PORTB |


   - #### **Interruptions Internes**

      <table>
        <thead>
          <tr>
            <th>Catégorie</th>
            <th>Source</th>
            <th>Description</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td rowspan="3"><strong><a href="#6-gestion-des-timers">Timers</a></strong></td>
            <td>Timer 0</td>
            <td>Débordement du Timer0</td>
          </tr>
          <tr>
            <td>Timers 1/3/5</td>
            <td>Débordement du Timer1/3/5</td>
          </tr>
          <tr>
            <td>Timers 2/4/6</td>
            <td>Débordement du Timer2/4/6</td>
          </tr>
          <tr>
            <td rowspan="3"><strong>Analogiques</strong></td>
            <td>ADC</td>
            <td>Fin de conversion A/N</td>
          </tr>
          <tr>
            <td>Comparateurs</td>
            <td>Interruption comparateur</td>
          </tr>
          <tr>
            <td>HLVD</td>
            <td>Détection basse tension</td>
          </tr>
          <tr>
            <td rowspan="3"><strong>Communication</strong></td>
            <td>USART RX</td>
            <td>Réception série</td>
          </tr>
          <tr>
            <td>USART TX</td>
            <td>Fin d’émission</td>
          </tr>
          <tr>
            <td>SSP</td>
            <td>SPI / I²C</td>
          </tr>
          <tr>
            <td rowspan="2"><strong>Contrôle</strong></td>
            <td>CCP1</td>
            <td>Capture / Compare / PWM</td>
          </tr>
          <tr>
            <td>CCP2</td>
            <td>Capture / Compare / PWM</td>
          </tr>
          <tr>
            <td rowspan="2"><strong>Mémoire / Bus</strong></td>
            <td>EEPROM / FLASH</td>
            <td>Fin d’écriture</td>
          </tr>
          <tr>
            <td>Bus Collision</td>
            <td>Collision sur le bus</td>
          </tr>
        </tbody>
      </table>


- ###  Mécanisme de Contrôle

   - #### Registres de Contrôle
      | **Catégorie** | **Registres** | **Fonction** | **Description** |
      |-------------|--------------|--------------|--------------------------------|
      | **[Contrôle Global](#registres-de-contrôle-global)** | `INTCON`, `INTCON2`, `INTCON3` | Interruptions de Base et Contrôle Global | **Bits GIE/PEIE :** <br>`0` = Interruptions désactivées <br>`1` = Interruptions activées<br><br>**Bits IE :** <br>`0` = Source désactivée <br>`1` = Source activée<br><br>**Bits IF :** <br>`0` = Pas d'événement <br>`1` = Événement détecté |
      | **[Priorité](#registres-de-priorité-ipr1-à-ipr5)** | `IPR1` à `IPR5` | Niveaux de Priorité **([si IPEN=1](#modes-de-fonctionnement))** | **Bits IPx :** <br>`0` = Priorité basse <br>`1` = Priorité haute (uniquement valide si `IPEN=1`) |
      | **[Activation](#registres-dactivation-pie1-à-pie5)** | `PIE1` à `PIE5` | Masques d'Activation Individuelle | **Bits IEx :** <br>`0` = Interruption masquée <br>`1` = Interruption autorisée |
      | **[Flags](#registres-de-flags-pir1-à-pir5)** | `PIR1` à `PIR5` | Indicateurs d'Événements Périphériques | **Bits IFx :** <br>`0` = Événement non survenu <br>`1` = Événement survenu (à effacer manuellement) |
      | **[Configuration](#registres-de-configuration)** | `RCON` | Choix du Mode | **Bit IPEN :** <br>`0` = Mode Priorité Unique (GIE/PEIE) <br>`1` = Mode Deux Priorités (GIEH/GIEL) |

      > - **INTCON** = **INT**errupt **CON**trol
      > - **IPR** = **I**nterrupt **P**riority **R**egister
      > - **PIE** = **P**eripheral **I**nterrupt **E**nable  
      > - **PIR** = **P**eripheral **I**nterrupt **R**equest
      > - **RCON** = **R**eset **CON**trol


   - #### Contrôle Global (Bits Système)  
      | Bit | Registre | Nom | Fonction | Description |
      |-----|----------|-----|----------|-------------|
      | **IPEN** | `RCON<7>` | Interrupt Priority Enable | Définit l'architecture d'interruption | `0` = Mode priorité unique<br>`1` = Mode deux priorités |
      | **GIEH/GIE** | `INTCON<7>` | Global Interrupt Enable (High) | Gardien principal (nom change selon IPEN) | `0` = Interruptions désactivées<br>`1` = Interruptions activées |
      | **GIEL/PEIE** | `INTCON<6>` | Global Interrupt Enable Low | Contrôle secondaire (nom change selon IPEN) | `0` = Périphériques désactivés<br>`1` = Périphériques activés |

      > - Si (Interruption == `INT0` || `Timer0` || `RB4-RB7`)
      >    - → **`GIE = 1`** Suffit
      > - Si (Interruption == `INT1` || `INT2` || `Timers1/2/3/4/5/6` || `CAN`)
      >    - → **`GIE = 1`** ET **`PEIE = 1`** Obligatoires


   - #### Contrôle par Source (Bits Spécifiques)  
      | Bit | Symbole | Localisation | Fonction | Description |
      |-----|---------|--------------|----------|-------------|
      | **IE** | `PIE1<bit>` | Registres PIE1-PIE5 | Autorise l'interruption pour ce périphérique spécifique | `0` = Source masquée<br>`1` = Source autorisée |
      | **IF** | `PIR1<bit>` | Registres PIR1-PIR5 | Indicateur matériel d'événement (set automatiquement) | `0` = Pas d'événement<br>`1` = Événement détecté (à effacer) |
      | **IP** | `IPR1<bit>` | Registres IPR1-IPR5 | Définit la priorité (seulement si `IPEN=1`) | `0` = Priorité basse<br>`1` = Priorité haute |


- ### Priorité des interruptions
   - #### Niveaux de Priorité
      | Priorité           | Adresse vecteur | Routine                |
      | ------------------ | --------------- | ---------------------- |
      | **Haute priorité** | `0008h`         | `void interrupt()`     |
      | **Basse priorité** | `0018h`         | `void interrupt_low()` |
      
      >  - La gestion des priorités est assurée par les registres `IPRx`.
      >  - **Exception :** l’interruption `INT0` ne possède pas de bit de priorité → toujours **haute priorité**.

   - #### Modes de Fonctionnement   
      | Bit | IPEN = 0 (Mode Simple) | IPEN = 1 (Mode Priorité) |
      |-----|------------------------|--------------------------|
      | **INTCON<7> :** `(GIE/GIEH)` | `GIE = 1` : Active **Tout**<br>`GIE = 0` : Désactive Tout | `GIEH = 1` : Active **Haute Priorité**<br>`GIEH = 0` : Désactive Tout |
      | **INTCON<6> :** `(PEIE/GIEL)` | `PEIE = 1` : Active **Périphériques**<br>`PEIE = 0` : Désactive Périphériques | `GIEL = 1` : Active **Basse Priorité**<br>`GIEL = 0` : Désactive Basse Priorité |


- ### Registres de Gestion d'Interruption

   - #### **Registres de Contrôle Global**
   
      - **INTCON - Contrôle Interruptions de Base**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **GIE/GIEH** | **PEIE/GIEL** | **TMR0IE** | **INT0IE** | **RBIE** | **TMR0IF** | **INT0IF** | **RBIF** |
      
         > - **Bits 7-6** : Contrôle global (noms changent selon IPEN)
         > - **Bits 5-3** : Activation des interruptions de base
         > - **Bits 2-0** : Flags d'interruption de base
      
      - **INTCON2 - Configuration Interruptions Externes**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **RBPU** | **INTEDG0** | **INTEDG1** | **INTEDG2** | — | **TMR0IP** | — | **RBIP** |
      
      - **INTCON3 - Interruptions Externes 1 & 2**
   
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **INT2IP** | **INT1IP** | — | **INT2IE** | **INT1IE** | — | **INT2IF** | **INT1IF** |
   
   
   - #### **Registres de Priorité (IPR1 à IPR5)**
   
      - **IPR1 - Priorités Périphériques (Groupe 1)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | — | **ADIP** | **RC1IP** | **TX1IP** | **SSP1IP** | **CCP1IP** | **TMR2IP** | **TMR1IP** |
      
      - **IPR2 - Priorités Périphériques (Groupe 2)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **OSCFIP** | **C1IP** | **C2IP** | **EEIP** | **BCL1IP** | **HLVDIP** | **TMR3IP** | **CCP2IP** |
      
      - **IPR3 - Priorités Périphériques (Groupe 3)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **SSP2IP** | **BCL2IP** | **RC2IP** | **TX2IP** | **CTMUIP** | **TMR5GIP** | **TMR3GIP** | **TMR1GIP** |
      
      - **IPR4 - Priorités Périphériques (Groupe 4)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | — | — | — | — | — | **CCP5IP** | **CCP4IP** | **CCP3IP** |
      
      - **IPR5 - Priorités Périphériques (Groupe 5)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | — | — | — | — | — | **TMR6IP** | **TMR5IP** | **TMR4IP** |
      
      > **Valeurs IP bits :** `0` = Basse priorité, `1` = Haute priorité (si IPEN=1)
   
   
   - #### **Registres d'Activation (PIE1 à PIE5)**
   
      - **PIE1 - Activation Périphériques (Groupe 1)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | — | **ADIE** | **RC1IE** | **TX1IE** | **SSP1IE** | **CCP1IE** | **TMR2IE** | **TMR1IE** |
      
      - **PIE2 - Activation Périphériques (Groupe 2)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **OSCFIE** | **C1IE** | **C2IE** | **EEIE** | **BCL1IE** | **HLVDIE** | **TMR3IE** | **CCP2IE** |
      
      - **PIE3 à PIE5** - Structure identique à IPR3-IPR5 mais avec suffixe **IE**
      

      > **Valeurs IE bits :** `0` = Désactivé, `1` = Activé
   
   
   - #### **Registres de Flags (PIR1 à PIR5)**
   
      - **PIR1 - Flags Périphériques (Groupe 1)**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | — | **ADIF** | **RC1IF** | **TX1IF** | **SSP1IF** | **CCP1IF** | **TMR2IF** | **TMR1IF** |
      
      - **PIR2 à PIR5** - Structure identique à PIE2-PIE5 mais avec suffixe **IF**
      
      > **Valeurs IF bits :** `0` = Pas d'événement, `1` = Événement détecté (à effacer manuellement)
      
   
   - #### **Registres de Configuration**
   
      - **ANSELB - Configuration Analogique/Digital**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | — | — | **ANSB5** | **ANSB4** | **ANSB3** | **ANSB2** | **ANSB1** | **ANSB0** |
      
      - **IOCB - Interrupt-on-Change Port B**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **IOCB7** | **IOCB6** | **IOCB5** | **IOCB4** | — | — | — | — |
      
      
      - **RCON - Registre de Contrôle Système**
      
         | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
         |-------|-------|-------|-------|-------|-------|-------|-------|
         | **IPEN** | **SBOREN** | — | **RI** | **TO** | **PD** | **POR** | **BOR** |
      
         > - **Bit 7 (IPEN)** : `0`=Mode simple, `1`=Mode deux priorités
         > - **Bits 4-0** : Indicateurs de reset (Power-on, Brown-out, etc.)


---

## **6. Gestion des Timers**
Un Timer est un périphérique matériel qui agit comme **un chronomètre** ou **un compteur** indépendant du processeur. Il permet d'exécuter des tâches répétitives avec une précision temporelle parfaite sans bloquer le programme principal.

- ### Caractéristiques des Timers

   | Caractéristique | Timer 0 | Timer 1/3/5 | Timer 2/4/6 |
   |-----------------|--------|------------|------------|
   | **Taille** | `8/16-bit` | `16-bit` (`TMRxH:TMRxL`) | `8-bit` (`TMRx` et `PRx`) |
   | **Mode** | Timer / Compteur | Timer / Compteur | Timer |
   | **Pré-diviseur (Prescaler)** | `8-bit` Programmable Software | Pré-diviseur `2-bit` | Programmable Software (`1:1`, `1:4`, `1:16`) |
   | **Post-diviseur (Postscaler)** | Non | Non | Programmable (`1:1` à `1:16`) |
   | **Source Horloge** | Interne (Système) / Externe | Interne / Externe / 32kHz | Interne |
   | **Interruption** | Overflow | Overflow | Sur match `TMRx=PRx` |
   | **Applications** |	Délais, Comptage | Mesure, RTC, CCP | PWM, Timing |
   
   > - **Pré-diviseur :** Diviseur de Fréquence **AVANT** le Compteur.
   >    - **Sans Pré-diviseur :** 1 tic = 1s
   >    - **Pré-diviseur `1:8` :** 8 tics = 1s
   > - **Post-diviseur :** Diviseur de Fréquence **APRÈS** le Compteur, sur l'interruption.
   >    - **Sans Post-diviseur :** Interruption à Chaque Overflow
   >    - **Post-diviseur `1:10` :** Interruption Tous les 10 Overflows


- ### Timer 0 (TMR0)
   - #### Registre de Contrôle – `T0CON`
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>TMR0ON</strong></td>
            <td><strong>T08BIT</strong></td>
            <td><strong>T0CS</strong></td>
            <td><strong>T0SE</strong></td>
            <td><strong>PSA</strong></td>
            <td colspan="3"><strong>T0PS&lt;2:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>

      - **Bit 7 : `TMR0ON` – Timer0 Activation**
         - **`0`** = **Désactivé**
         - **`1`** = **Activé**
      
      - **Bit 6 : `T08BIT` – Mode Timer0**
         - **`0`** = **Mode `16-bit`**
         - **`1`** = **Mode `8-bit`**
      
      - **Bit 5 : `T0CS` – Source d'Horloge**
         - **`0`** = Horloge **Interne** (Cycle d'Instruction **Fosc/4**)
         - **`1`** = Horloge **Externe** (Broche **RA4 / T0CKI**)
      
      - **Bit 4 : `T0SE` – Front d'Horloge Externe**
         - **`0`** = Front **Montant** (LOW→HIGH)
         - **`1`** = Front **Descendant** (HIGH→LOW)
      
      - **Bit 3 : `PSA` – Attribution du Pré-diviseur**
         - **`0`** = **Attribué**
         - **`1`** = **NON Attribué**
      
      - **Bits 2-0 : `T0PS<2:0>` – Sélection du Pré-diviseur**
       
         | T0PS2 | T0PS1 | T0PS0 | Valeur Pré-diviseur |
         |-------|-------|-------|-------------------|
         | 0 | 0 | 0 | 1:2 |
         | 0 | 0 | 1 | 1:4 |
         | 0 | 1 | 0 | 1:8 |
         | 0 | 1 | 1 | 1:16 |
         | 1 | 0 | 0 | 1:32 |
         | 1 | 0 | 1 | 1:64 |
         | 1 | 1 | 0 | 1:128 |
         | 1 | 1 | 1 | 1:256 |

   - #### Mode Fonctionnement

      | Champ / Bit                 | **Mode Timer** (`T0CS = 0`)                      | **Mode Compteur** (`T0CS = 1`)                                            |
      | --------------------------- | ------------------------------------------------ | ------------------------------------------------------------------------- |
      | **T0CON<5> :** `T0CS`       | **`0`** : Source **Interne** (**Fosc/4**)        | **`1`** : Source **Externe** (Broche **RA4 / T0CKI**)                     |
      | **T0CON<4> :** `T0SE`       | **Ignoré** (Sans Effet)                          | **`0`** : Comptage sur **Front Montant**<br>**`1`** : Comptage sur **Front Descendant** |

   - #### Registres Associés

      <table>
        <thead>
          <tr>
            <th>Name</th>
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
            <td><strong><a href="#mécanisme-de-contrôle">INTCON</a></strong></td>
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
            <td><strong><a href="#mécanisme-de-contrôle">INTCON2</a></strong></td>
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
            <td><strong>T0CON</strong></td>
            <td>TMR0ON</td>
            <td>T08BIT</td>
            <td>T0CS</td>
            <td>T0SE</td>
            <td>PSA</td>
            <td align="center" colspan="3">T0PS&lt;2:0&gt;</td>
          </tr>
          <tr>
            <td><strong>TMR0H</strong></td>
            <td align="center" colspan="8">Timer0 Register, High Byte</strong></td>
          </tr>
          <tr>
            <td><strong>TMR0L</strong></td>
            <td align="center" colspan="8">Timer0 Register, Low Byte</strong></td>
          </tr>
        </tbody>
      </table>

      > - Si **T08BIT = 1 (`8-bit`)** :
      >    - `TMR0H` est **Ignoré**
      >    - Seul `TMR0L` est **Utilisé**


   - #### Période de Débordement $`T_0`$ (Overflow)
      - ##### En Mode Timer (`T0CS = 0`)
 
         |        Étapes                            |             En Mode Timer (`T0CS = 0`)                                             |
         | ---------------------------------------- | :--------------------------------------------------------------------------------: |
         | **Étape 1 :** Période d’Horloge Interne  | <div align="center">**$`T_H = \frac{4}{F_{osc}}`$**                                |
         | **Étape 2 :** Choix du Pré-diviseur      | <div align="center">**$`\text{Prediv} \in \{1, 2, 4, 8, 16, 32, 64, 128, 256\}`$** |
         | **Étape 3 :** Période d’un Incrément     | <div align="center">**$`T_{inc}​ = \text{Prediv} \times T_H`$**                     |
         | **Étape 4 :** Nombre d’Itérations        | <div align="center">**$`N = \frac{T_{désiré}}{T_{inc}}`$**                         |
         | **Étape 5 :** Valeur Initiale à Charger  | <div align="center">**$`\text{TMR0}_{init} = \text{Max} - \text{N} + 1`$**         |
         | **Formule Finale**                       | <div align="center">**$`T_0 ​= N \times \text{Prediv} \times \frac{4}{F_{osc​}}`$**  |​​​​
 
         > - **Vérifie :** **$`T_{inc}​ < 256`$** (Mode `8-bit`) ou **$`< 65536`$** (Mode `16-bit`)
         > - **Optimise :** Choisis le Pré-diviseur qui donne un Nombre d’Itérations Proche d'un Entier
         
      - ##### En Mode Compteur (`T0CS = 1`)

         |        Étapes                               |             En Mode Compteur (`T0CS = 1`)                                                 |
         | ------------------------------------------- | :---------------------------------------------------------------------------------------: |
         | **Étape 1 :** Choix du Pré-diviseur         | <div align="center">**$`\text{Prediv} \in \{1, 2, 4, 8, 16, 32, 64, 128, 256\}`$**        |
         | **Étape 2 :** Nombre d’Événements à Compter | <div align="center">**$`N = \text{Nombre d’Impulsions Souhaitées}`$**                     |
         | **Étape 3 :** Valeur Initiale à Charger     | <div align="center">**$`\text{TMR0}_{init} = \text{Max} - \text{N} + 1`$**                |
         | **Formule Finale**                          | <div align="center">**$`\text{Débordement Aprés N } \times \text{ Prediv Impulsions}`$**  |
 
     
     > - **Valeur Maximale**
     >    - **$`Max(8bits) = 255`$**
     >    - **$`Max(16bits) = 65535`$**
      
         
<!-- 
- ### Timer 1/3/5 (TMR1/3/5)

   - #### Registre de Contrôle – `TxCON` (x = 1, 3, 5)
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td colspan="2"><strong>TMRxCS&lt;1:0&gt;</strong></td>
            <td colspan="2"><strong>TXCKPS&lt;1:0&gt;</strong></td>
            <td><strong>TXSOSCEN</strong></td>
            <td><strong>TXSYNC</strong></td>
            <td><strong>TXRD16</strong></td>
            <td><strong>TMRxON</strong></td>
          </tr>
        </tbody>
      </table>

      - **Bits 7-6 : `TMRxCS<1:0>` – Sélection de la Source d'Horloge du Timer**
         | TMRxCS1 | TMRxCS0 | Source d'Horloge |
         |---------|---------|------------------|
         | 0 | 0 | **Horloge d'Instruction (`Fosc/4`)** |
         | 0 | 1 | **Horloge Système (`Fosc`)** |
         | 1 | 0 | **Source Externe (Broche `TXCKI`) *ou* Oscillateur Secondaire** (selon **`TXSOSCEN`**) |
         | 1 | 1 | **Réservé – Ne pas Utiliser** |

         > - Si **`TMRxCS<1:0> = 10`** et **`TXSOSCEN = 0`** : Horloge Externe sur **Broche TXCKI** (Front Montant).
         > - Si **`TMRxCS<1:0> = 10`** et **`TXSOSCEN = 1`** : **Oscillateur à Quartz (Secondaire)** sur Broches **SOSC/SOSCO**.

      - **Bits 5-4 : `TXCKPS<1:0>` – Sélection du Pré-diviseur d'Horloge**
         | TXCKPS1 | TXCKPS0 | Valeur du Pré-diviseur |
         |---------|---------|------------------------|
         | 0 | 0 | **1:1** (Pas de division) |
         | 0 | 1 | **1:2** |
         | 1 | 0 | **1:4** |
         | 1 | 1 | **1:8** |

      - **Bit 3 : `TXSOSCEN` – Activation de l'Oscillateur Secondaire**
         - **`0`** = **Désactivé**
         - **`1`** = **Activé** (circuit oscillateur secondaire dédié)

      - **Bit 2 : `TXSYNC` – Synchronisation de l'Horloge Externe**
         - Si `TMRxCS<1:0> = 1X` (Source Externe) :
            - **`0`** = Synchronisation avec l'**Horloge Système (Fosc)**
            - **`1`** = **Pas de synchronisation**
         - Si `TMRxCS<1:0> = 0X` (Source Interne) : **Ce bit est ignoré.**

      - **Bit 1 : `TXRD16` – Mode de Lecture/Écriture `16-Bits`**
         - **`0`** = Lecture/écriture en **deux opérations `8-bits`**
         - **`1`** = Lecture/écriture en **une opération `16-bits`**

      - **Bit 0 : `TMRxON` – Activation du Timer**
         - **`0`** = **Arrêt** – Réinitialise la bascule de gâchette du Timer
         - **`1`** = **Marche**

   - #### Registre de Contrôle de la Porte (Gate) – `TXGCON` (x = 1, 3, 5)
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>TMRxGE</strong></td>
            <td><strong>TxGPOL</strong></td>
            <td><strong>TxGTM</strong></td>
            <td><strong>TxGSPM</strong></td>
            <td><strong>TxGGO/DONE</strong></td>
            <td><strong>TxGVAL</strong></td>
            <td colspan="2"><strong>TxGSS&lt;1:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>

      - **Bit 7 : `TMRxGE` – Activation de la Fonction Porte du Timer**
         - Si **`TMRxON = 0`** : Ce bit est **ignoré**.
         - Si **`TMRxON = 1`** :
            - **`0`** = Le Timer compte **indépendamment** de la fonction porte.
            - **`1`** = Le comptage du Timer est **contrôlé** par la fonction porte.

      - **Bit 6 : `TxGPOL` – Polarité de la Porte du Timer**
         - **`0`** = Porte **active à l'état BAS** (Le Timer compte quand la porte est BASSE).
         - **`1`** = Porte **active à l'état HAUT** (Le Timer compte quand la porte est HAUTE).

      - **Bit 5 : `TxGTM` – Mode Basculé (Toggle) de la Porte**
         - **`0`** = **Désactivé** – La bascule de la porte est réinitialisée.
         - **`1`** = **Activé** – La bascule de la porte du Timer bascule à **chaque front montant** de la source sélectionnée.

      - **Bit 4 : `TxGSPM` – Mode Impulsion Unique (Single-Pulse) de la Porte**
         - **`0`** = **Désactivé**
         - **`1`** = **Activé** – Le mode impulsion unique contrôle la porte du Timer.

      - **Bit 3 : `TxGGO/DONE` – État d'Acquisition en Mode Impulsion Unique**
         - **`0`** = L'acquisition de l'impulsion unique est **terminée** ou **n'a pas démarré**.
         - **`1`** = L'acquisition est **prête** et attend un front déclencheur.
         > - *Ce bit est **Automatiquement Réinitialisé** quand `TxGSPM` est mis à `0`.*

      - **Bit 2 : `TxGVAL` – État Actuel de la Porte du Timer (Lecture seule)**
         - Indique l'état actuel du signal de porte qui serait appliqué au Timer (`TMRxH:TMRxL`).
         > - *Non affecté par l'activation de la porte (`TMRxGE`).*

      - **Bits 1-0 : `TxGSS<1:0>` – Sélection de la Source de la Porte du Timer**
         | TxGSS1 | TxGSS0 | Source de la Porte |
         |--------|--------|---------------------|
         | 0 | 0 | **Broche de la porte du Timer (Timer Gate Pin)** |
         | 0 | 1 | **Signal de correspondance (Match) du Timer2/4/6** (Sortie de `PR2/PR4/PR6`) |
         | 1 | 0 | **Sortie du Comparateur 1** (optionnellement synchronisée – `sync_C1OUT`) |
         | 1 | 1 | **Sortie du Comparateur 2** (optionnellement synchronisée – `sync_C2OUT`) |

      - #### Mode Fonctionnement de la Porte

         | Champ / Bit               | **Fonction**                                                                                                     |
         |---------------------------|------------------------------------------------------------------------------------------------------------------|
         | **`TMRxGE`**              | Active (`1`) ou contourne (`0`) le contrôle du comptage par la porte, uniquement si le Timer est activé (`TMRxON=1`). |
         | **`TxGSS<1:0>`**          | Définit l'origine du signal qui contrôle la porte (broche, autre timer, comparateur).                           |
         | **`TxGPOL`**              | Définit si le comptage a lieu quand le signal de porte est HAUT (`1`) ou BAS (`0`).                              |
         | **`TxGTM`**               | Permet à la porte de basculer son état à chaque front montant de sa source, créant un signal alterné.            |
         | **`TxGSPM` & `TxGGO/DONE`**| Permet de capturer une **seule impulsion** contrôlée par la porte. `TxGGO/DONE` indique l'état de l'acquisition.|


   - #### Registres Associés (x = 1, 3, 5)
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
            <td><strong>TxCON</strong></td>
            <td colspan="2">TMRxCS&lt;1:0&gt;</td>
            <td colspan="2">TxCKPS&lt;1:0&gt;</td>
            <td>TxSOSCEN</td>
            <td>TxSYNC</td>
            <td>TxRD16</td>
            <td>TMRxON</td>
          </tr>
          <tr>
            <td><strong>TxGCON</strong></td>
            <td>TMRxGE</td>
            <td>TxGPOL</td>
            <td>TxGTM</td>
            <td>TxGSPM</td>
            <td>TxGGO/<br>DONE</td>
            <td>TxGVAL</td>
            <td colspan="2">TxGSS&lt;1:0&gt;</td>
          </tr>
          <tr>
            <td><strong>TMRxH</strong></td>
            <td align="center" colspan="8">Timerx Register, High Byte</td>
          </tr>
          <tr>
            <td><strong>TMRxL</strong></td>
            <td align="center" colspan="8">Timerx Register, Low Byte</td>
          </tr>
        </tbody>
      </table>

      > Consultez les sections suivantes pour la configuration :  
      > - **[Activation des interruptions (`PIEx`)](#registres-dactivation-pie1-à-pie5)**
      > - **[Drapeaux d'interruption (`PIRx`)](#registres-de-flags-pir1-à-pir5)**
      > - **[Priorités d'interruption (`IPRx`)](#registres-de-priorité-ipr1-à-ipr5)**
 -->

   
- ### Timer 2/4/6 (TMR2/4/6)
   - #### Registre de Contrôle – `TxCON` (x = 2, 4, 6)
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>—</strong></td>
            <td colspan="4"><strong>TxOUTPS&lt;3:0&gt;</strong></td>
            <td><strong>TMRxON</strong></td>
            <td colspan="2"><strong>TxCKPS&lt;1:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>

      - **Bits 6-3 : `TxOUTPS<3:0>` – Sélection du Post-diviseur de Sortie**
         | TxOUTPS3 | TxOUTPS2 | TxOUTPS1 | TxOUTPS0 | Valeur du Post-diviseur |
         |----------|----------|----------|----------|-------------------------|
         | 0 | 0 | 0 | 0 | **1:1** (Pas de division) |
         | 0 | 0 | 0 | 1 | **1:2** |
         | 0 | 0 | 1 | 0 | **1:3** |
         | 0 | 0 | 1 | 1 | **1:4** |
         | 0 | 1 | 0 | 0 | **1:5** |
         | 0 | 1 | 0 | 1 | **1:6** |
         | 0 | 1 | 1 | 0 | **1:7** |
         | 0 | 1 | 1 | 1 | **1:8** |
         | 1 | 0 | 0 | 0 | **1:9** |
         | 1 | 0 | 0 | 1 | **1:10** |
         | 1 | 0 | 1 | 0 | **1:11** |
         | 1 | 0 | 1 | 1 | **1:12** |
         | 1 | 1 | 0 | 0 | **1:13** |
         | 1 | 1 | 0 | 1 | **1:14** |
         | 1 | 1 | 1 | 0 | **1:15** |
         | 1 | 1 | 1 | 1 | **1:16** |

      - **Bit 2 : `TMRxON` – Activation du Timerx**
         - **`0`** = **Désactivé**
         - **`1`** = **Activé**

      - **Bits 1-0 : `TxCKPS<1:0>` – Sélection du Pré-diviseur d'Horloge**
         | TxCKPS1 | TxCKPS0 | Valeur du Pré-diviseur |
         |---------|---------|------------------------|
         | 0 | 0 | **1:1** (Pas de division) |
         | 0 | 1 | **1:4** |
         | 1 | x | **1:16** |

   - #### Période de Timer `PRx`
 
      | Étapes                                       | En Mode Timer (`TMRxON = 1`)                                                    |
      |----------------------------------------------|:-------------------------------------------------------------------------------:|
      | **Étape 1 :** Période d’Horloge Interne | <div align="center">**$`T_H = \frac{4}{F_{osc}}`$**</div>                         |
      | **Étape 2 :** Choix du Pré-diviseur    | <div align="left"> • **Timer2/6 : $`\text{Prédiviseur} \in \{1, 4, 16\}`$** <br> • **Timer4 : $`\text{Prédiviseur} \in \{1, 4, 16, 32, 64, 128\}`$**</div> |
      | **Étape 3 :** Choix du Post-diviseur (Si Disponible) | <div align="left"> • **Timer2/6 :** **$`\text{Postdiviseur} \in \{1..16\}`$** <br> • **Timer4 : $`\text{Postdiviseur} = 1`$**</div> |
      | **Étape 4 :** Valeur Période (`PRx`)     | <div align="center">**$`PRx = \frac{T_{x}}{\text{Prédiviseur} \times T_H \times Postdiviseur} - 1`$**</div> |
      | **Étape 5 :** Nombre d’Interruptions | <div align="center">**$`N_x = \frac{T_{donné}}{T_{x}}`$**</div> |

      > - Choisir **$`T_{x}`$** tel que **$`0 \le PRx \le 255`$**
      > - **Période d’un Incrément : $`T_{inc}​ = \text{Prediv} \times T_H`$**


   - #### Registres Associés (x = 2, 4, 6)
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
        <tbody align="center">
          <tr>
            <td><strong>TxCON</strong></td>
            <td>—</td>
            <td colspan="4">TxOUTPS&lt;3:0&gt;</td>
            <td>TMRxON</td>
            <td colspan="2">TxCKPS&lt;1:0&gt;</td>
          </tr>
          <tr>
            <td><strong>PRx</strong></td>
            <td align="center" colspan="8">Valeur de Période du Timerx</td>
          </tr>
          <tr>
            <td><strong>TMRx</strong></td>
            <td align="center" colspan="8">Compteur du Timerx (8 bits)</td>
          </tr>
        </tbody>
      </table>
      
      > Consultez les sections suivantes pour la configuration :  
      > - **[Activation des interruptions (`PIEx`)](#registres-dactivation-pie1-à-pie5)**
      > - **[Drapeaux d'interruption (`PIRx`)](#registres-de-flags-pir1-à-pir5)**
      > - **[Priorités d'interruption (`IPRx`)](#registres-de-priorité-ipr1-à-ipr5)**





---






## **7. Gestion de CAN**
Le **Convertisseur Analogique-Numérique (CAN)** permet de convertir une **Signal Analogique** en une **Valeur Numérique sur 10 bits** (0 à 1023).
>   - Entrées Analogiques multiplexées **(`AN0` à `AN27`)**
>   - Résultat Stocké dans **`ADRESH:ADRESL`**
>   - Références de Tension configurables (**$`V_{DD}`$, $`V_{SS}`$, $`V_{REF±}`$, $`FVR`$**)
>   - Peut générer une interruption en fin de Conversion

- ### Étapes de Conversion A/N

   | Étape | Action | Description |
   |-------|--------|-------------|
   | **1** | **[Configurer le Port](#4-ports-dentréesortie-es)** | • `TRISx = 1` (Entrée)<br>• `ANSELx = 1` (Analogique) |
   | **2** | **[Configurer le Module CAN](#registres-de-contrôle-2)** | • `ADCS` ([Vitesse](#adcon2---configuration-de-lhorloge-et-du-format))<br>• `PVCFG/NVCFG` ([Références](#adcon1---configuration-des-références-de-tension))<br>• `CHS` ([Canal](#adcono---sélection-de-canal-et-activation-adc))<br>• `ADFM` ([Format](#adcon2---configuration-de-lhorloge-et-du-format))<br>• `ACQT` ([Délai](#adcon2---configuration-de-lhorloge-et-du-format))<br>• `ADON = 1` ([Activation](#adcono---sélection-de-canal-et-activation-adc)) |
   | **3** | **[Configurer l'Interruption](#5-gestion-des-interruptions)** (Optionnel) | • `ADIF = 0`<br>• `ADIE = 1`<br>• `PEIE = 1`<br>• `GIE = 1` |
   | **4** | **Attendre Acquisition** | Attente du **TACQ** (Si Manuel) |
   | **5** | **Démarrer Conversion** | `GO/DONE = 1` |
   | **6** | **Attendre Fin** | • Vérifier `GO/DONE = 0`<br>• OU `ADIF = 1` |
   | **7** | **Lire Résultat** | Lecture `ADRESH:ADRESL` |
   | **8** | **Désactiver Drapeau (Flag)** | `ADIF = 0` (Si Interruption) |

  > - **Configuration (Étapes 1-3) :** Préparation des registres et du matériel
  > - **Exécution (Étapes 4-7) :** Lancement et lecture de la conversion
  > - **Nettoyage (Étapes 8) :** Gestion des interruptions

- ### Registres de Contrôle

   - #### `ADCONO` - Sélection de Canal et Activation ADC
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td>—</td>
            <td colspan="5"><strong>CHS&lt;4:0&gt;</strong></td>
            <td><strong>GO/DONE</strong></td>
            <td><strong>ADON</strong></td>
          </tr>
        </tbody>
      </table>
      
      - **Bits 6-2 : `CHS<4:0>` – Sélection du Canal Analogique**
           | CHS4 | CHS3 | CHS2 | CHS1 | CHS0 | Canal | Broche |
           |------|------|------|------|------|-------|--------|
           | 0 | 0 | 0 | 0 | 0 | **AN0** | RA0 |
           | 0 | 0 | 0 | 0 | 1 | **AN1** | RA1 |
           | 0 | 0 | 0 | 1 | 0 | **AN2** | RA2 |
           | 0 | 0 | 0 | 1 | 1 | **AN3** | RA3 |
           | 0 | 0 | 1 | 0 | 0 | **AN4** | RA5 |
           | 0 | 0 | 1 | 0 | 1 | **AN5** | RE0 |
           | 0 | 0 | 1 | 1 | 0 | **AN6** | RE1 |
           | 0 | 0 | 1 | 1 | 1 | **AN7** | RE2 |
           | 0 | 1 | 0 | 0 | 0 | **AN8** | RB2 |
           | 0 | 1 | 0 | 0 | 1 | **AN9** | RB3 |
           | 0 | 1 | 0 | 1 | 0 | **AN10** | RB1 |
           | 0 | 1 | 0 | 1 | 1 | **AN11** | RB4 |
           | 0 | 1 | 1 | 0 | 0 | **AN12** | RB0 |
           | 0 | 1 | 1 | 0 | 1 | **AN13** | RB5 |
           | 0 | 1 | 1 | 1 | 0 | **AN14** | RB6 |
           | 0 | 1 | 1 | 1 | 1 | **AN15** | RB7 |
           | 1 | 0 | 0 | 0 | 0 | **AN16** | RC2 |
           | 1 | 0 | 0 | 0 | 1 | **AN17** | RC3 |
           | 1 | 0 | 0 | 1 | 0 | **AN18** | RC6 |
           | 1 | 0 | 0 | 1 | 1 | **AN19** | RC7 |
           | 1 | 0 | 1 | 0 | 0 | **AN20** | RD0 |
           | 1 | 0 | 1 | 0 | 1 | **AN21** | RD1 |
           | 1 | 0 | 1 | 1 | 0 | **AN22** | RD2 |
           | 1 | 0 | 1 | 1 | 1 | **AN23** | RD3 |
           | 1 | 1 | 0 | 0 | 0 | **AN24** | RD4 |
           | 1 | 1 | 0 | 0 | 1 | **AN25** | RD5 |
           | 1 | 1 | 0 | 1 | 0 | **AN26** | RD6 |
           | 1 | 1 | 0 | 1 | 1 | **AN27** | RD7 |
           | 1 | 1 | 1 | 0 | 0 | **RÉSERVÉ** | — |
           | 1 | 1 | 1 | 0 | 1 | **CTMU** | Module CTMU interne |
           | 1 | 1 | 1 | 1 | 0 | **CNA** | Module DAC interne |
           | 1 | 1 | 1 | 1 | 1 | **FVR BUF2** | Référence FVR (1.024V/2.048V/4.096V) |
      
      - **Bit 1 : `GO/DONE` – Statut de Conversion A/D**
        - **`1`** = **Conversion en cours** – Démarre une nouvelle conversion si écrit à `1`
        - **`0`** = **Conversion terminée** – Mis à `0` automatiquement par le matériel après conversion
        
        > - Écrire `1` pour démarrer une conversion.
        > - Lire `0` pour vérifier que la conversion est terminée.
      
      - **Bit 0 : `ADON` – Activation du Convertisseur A/D**
        - **`1`** = **ADC activé** – Alimentation et circuits activés
        - **`0`** = **ADC désactivé** – Économie d'énergie
   
   
   - #### `ADCON1` - Configuration des Références de Tension
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>TRIGSEL</strong></td>
            <td>—</td>
            <td>—</td>
            <td>—</td>
            <td colspan="2"><strong>PVCFG&lt;1:0&gt;</strong></td>
            <td colspan="2"><strong>NVCFG&lt;1:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>
      
      - **Bit 7 : `TRIGSEL` – Sélection du Déclencheur Spécial**
        - **`1`** = **CTMU** – Déclenchement par le module CTMU (Charge Time Measurement Unit)
        - **`0`** = **CCP5** – Déclenchement par le module Capture/Compare/PWM 5
      
      - **Bits 3-2 : `PVCFG<1:0>` – Configuration de la Référence Positive VREF+**
        | PVCFG1 | PVCFG0 | Référence Positive VREF+ |
        |--------|--------|---------------------------|
        | 0 | 0 | **VDD** – Tension d'alimentation du microcontrôleur |
        | 0 | 1 | **Broche VREF+ (RA3)** – Référence externe |
        | 1 | 0 | **FVR BUF2** – Référence interne fixe (FVRCON) |
        | 1 | 1 | **RÉSERVÉ** (par défaut = VDD) |
      
      - **Bits 1-0 : `NVCFG<1:0>` – Configuration de la Référence Négative VREF-**
        | NVCFG1 | NVCFG0 | Référence Négative VREF- |
        |--------|--------|---------------------------|
        | 0 | 0 | **VSS** – Masse (0V) |
        | 0 | 1 | **Broche VREF- (RA2)** – Référence externe |
        | 1 | 0 | **RÉSERVÉ** (par défaut = VSS) |
        | 1 | 1 | **RÉSERVÉ** (par défaut = VSS) |
   
   
   - #### `ADCON2` - Configuration de l'Horloge et du Format
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>ADFM</strong></td>
            <td>—</td>
            <td colspan="3"><strong>ACQT&lt;2:0&gt;</strong></td>
            <td colspan="3"><strong>ADCS&lt;2:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>
      
      - **Bit 7 : `ADFM` – Format du Résultat de Conversion**
              <table>
                 <tr>
                    <th colspan="9">ADRESH (High Byte)</th>
                    <th colspan="8">ADRESL (Low Byte)</th>
                 </tr>
                 <tr>
                     <td rowspan="2"><strong>ADFM=0</strong></td>
                     <td><strong>Bit 7</td>
                     <td><strong>Bit 6</td>
                     <td><strong>Bit 5</td>
                     <td><strong>Bit 4</td>
                     <td><strong>Bit 3</td>
                     <td><strong>Bit 2</td>
                     <td><strong>Bit 1</td>
                     <td><strong>Bit 0</td>
                     <td><strong>Bit 7</td>
                     <td><strong>Bit 6</td>
                     <td>Bit 5</td>
                     <td>Bit 4</td>
                     <td>Bit 3</td>
                     <td>Bit 2</td>
                     <td>Bit 1</td>
                     <td>Bit 0</td>
                 </tr>
                 <tr>
                     <td colspan="8" align="center">MSB ← 10-bit A/D Result → LSB</td>
                     <td colspan="2" align="center">Bits [1:0]</td>
                     <td colspan="6" align="center">―</td>
                 </tr>
                 <tr>
                     <td rowspan="2"><strong>ADFM=1</strong></td>
                     <td>Bit 7</td>
                     <td>Bit 6</td>
                     <td>Bit 5</td>
                     <td>Bit 4</td>
                     <td>Bit 3</td>
                     <td>Bit 2</td>
                     <td><strong>Bit 1</td>
                     <td><strong>Bit 0</td>
                     <td><strong>Bit 7</td>
                     <td><strong>Bit 6</td>
                     <td><strong>Bit 5</td>
                     <td><strong>Bit 4</td>
                     <td><strong>Bit 3</td>
                     <td><strong>Bit 2</td>
                     <td><strong>Bit 1</td>
                     <td><strong>Bit 0</td>
                 </tr>
                 <tr>
                     <td colspan="6" align="center">―</td>
                     <td colspan="2" align="center">Bits [9:8]</td>
                     <td colspan="8" align="center">MSB ← 10-bit A/D Result → LSB</td>
                 </tr>
               </table>
      
      - **Bits 5-3 : `ACQT<2:0>` – Sélection du Temps d'Acquisition**
        | ACQT2 | ACQT1 | ACQT0 | Temps d'Acquisition |
        |-------|-------|-------|---------------------|
        | 0 | 0 | 0 | **0 TAD** |
        | 0 | 0 | 1 | **2 TAD** |
        | 0 | 1 | 0 | **4 TAD** |
        | 0 | 1 | 1 | **6 TAD** |
        | 1 | 0 | 0 | **8 TAD** |
        | 1 | 0 | 1 | **12 TAD** |
        | 1 | 1 | 0 | **16 TAD** |
        | 1 | 1 | 1 | **20 TAD** |
      
        > - **TAD** = Temps d'Horloge de CAN (ADC Clock Period)
        > - **TACQ** = Temps d'Acquisition du CAN (ADC Acquisition Time)
      
      - **Bits 2-0 : `ADCS<2:0>` – Sélection de l'Horloge CAN**
        | ADCS2 | ADCS1 | ADCS0 | Horloge CAN (TAD) | Formule       |
        |-------|-------|-------|-------------------| :-------------: |
        | 0 | 0 | 0 | **Fosc/2** | $`T_{AD} = 2 \times T_{osc}`$    |
        | 1 | 0 | 0 | **Fosc/4** | $`T_{AD} = 4 \times T_{osc}`$    |
        | 0 | 0 | 1 | **Fosc/8** | $`T_{AD} = 8 \times T_{osc}`$    |
        | 1 | 0 | 1 | **Fosc/16** | $`T_{AD} = 16 \times T_{osc}`$  |
        | 0 | 1 | 0 | **Fosc/32** | $`T_{AD} = 32 \times T_{osc}`$  |
        | 1 | 1 | 0 | **Fosc/64** | $`T_{AD} = 64 \times T_{osc}`$  |
        | x | 1 | 1 | **FRC** |        ―             |
      
         >   | **Étape** | **Action**                    | **Formule**                             |
         >   | --------- | ----------------------------- | --------------------------------------- |
         >   | 1         | **Période d’Horloge**         | $`T_{osc} = \dfrac{1}{F_{osc}}`$        |
         >   | 2         | **Période du CAN**            | $`T_{AD} = \text{ADCS} \times T_{osc}`$ |
         >   | 3         | **Choisir `ADCS`**            | $`T_{AD} \ge 1\mu s`$                  |
         
         > - **Plus Petit Diviseur Valide = Vitesse Maximale**
         > - **Modifier `ACQT` Ne Change pas la Vitesse de Conversion**



   - #### `FVRCON` - Contrôle de la Référence de Tension Fixe
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>FVREN</strong></td>
            <td><strong>FVRST</strong></td>
            <td colspan="2"><strong>FVRS&lt;1:0&gt;</strong></td>
            <td>—</td>
            <td>—</td>
            <td>—</td>
            <td>—</td>
          </tr>
        </tbody>
      </table>
      
      - **Bit 7 : `FVREN` – Activation de la Référence de Tension Fixe**
        - **`0`** = **Désactivé** – Le module FVR est éteint (économie d'énergie)
        - **`1`** = **Activé** – Le module FVR est alimenté et opérationnel
      
      - **Bit 6 : `FVRST` – Indicateur de Prêt du FVR**
        - **`0`** = **Non prêt** – La sortie FVR n'est pas stable ou le module est désactivé
        - **`1`** = **Prêt** – La tension de référence est stable et peut être utilisée
        
        > **Note** : Ce bit est **lecture seule**. Il faut attendre qu'il passe à `1` après l'activation du FVR avant d'utiliser la référence.
      
      - **Bits 5-4 : `FVRS<1:0>` – Sélection du Niveau de Tension de Sortie**
        | FVRS1 | FVRS0 | Gain | Tension de Sortie (Typique) |
        |-------|-------|------|-----------------------------|
        | 0 | 0 | **Désactivé** | — |
        | 0 | 1 | **1×** | 1,024 V |
        | 1 | 0 | **2×** | 2,048 V |
        | 1 | 1 | **4×** | 4,096 V |
        
        > **Application** : 
        > - **1,024 V** : Pour CAN (ADC) basse tension
        > - **2,048 V / 4,096 V** : Pour comparateurs analogiques ou CAN haute précision

- ### Registres Associés
   <table>
     <thead>
       <tr>
         <th>Name</th>
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
         <td><strong>ADCON0</strong></td>
         <td>—</td>
         <td align="center" colspan="5">CHS&lt;4:0&gt;</td>
         <td>GO/DONE</td>
         <td>ADON</td>
       </tr>
       <tr>
         <td><strong>ADCON1</strong></td>
         <td>TRIGSEL</td>
         <td>—</td>
         <td>—</td>
         <td>—</td>
         <td align="center" colspan="2">PVCFG&lt;1:0&gt;</td>
         <td align="center" colspan="2">NVCFG&lt;1:0&gt;</td>
       </tr>
       <tr>
         <td><strong>ADCON2</strong></td>
         <td>ADFM</td>
         <td>—</td>
         <td align="center" colspan="3">ACQT&lt;2:0&gt;</td>
         <td align="center" colspan="3">ADCS&lt;2:0&gt;</td>
       </tr>
       <tr>
         <td><strong>ADRESH</strong></td>
         <td align="center" colspan="8">A/D Result, High Byte</td>
       </tr>
       <tr>
         <td><strong>ADRESL</strong></td>
         <td align="center" colspan="8">A/D Result, Low Byte</td>
       </tr>
     </tbody>
   </table>
   
   > Consultez les sections suivantes pour la configuration :
   > - **[Ports d’Entrée/Sortie (E/S) (`TRISx`, `ANSELx`)](#4-ports-dentréesortie-es)**
   > - **[Activation des interruptions (`PIEx`)](#registres-dactivation-pie1-à-pie5)**
   > - **[Drapeaux d'interruption (`PIRx`)](#registres-de-flags-pir1-à-pir5)**
   > - **[Priorités d'interruption (`IPRx`)](#registres-de-priorité-ipr1-à-ipr5)**



- ### Fonctionnes Avancé MikroC
   | **Fonction**                  | **Description**                                |
   | ----------------------------- | ---------------------------------------------- |
   | **`ADC_Init()`**              | **Initialise** le Module CAN.                      |
   | **`ADC_Get_Sample(channel)`** | **Lit Un** Échantillon sur le Canal Sélectionné.   |
   | **`ADC_Read(channel)`**       | **Initialise** et **Lit** le CAN en une Seule Commande. |


## **8. Gestion de CNA**
Le **Convertisseur Numérique-Analogique (CNA)** convertit une **Donnée Numérique** en une **Tension Analogique** proportionnelle, définie par des Tensions de Référence, avec un Nombre Fini de Niveaux (**32** pour un CNA **`5-bits`**).


- ### Étapes de Conversion N/A
   | **Étape** | **Action**                                  | **Description**                                                                                                         |
   | --------- | ------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
   | **1**     | **Source de Référence Positive** | Sélection de $`V_{SRC+}`$ :<br>• **VDD**<br>• **VREF+ Externe**<br>• **FVR BUF1**                                         |
   | **2**     | **Source de Référence Négative** | Sélection de $`V_{SRC-}`$ :<br>• **VSS**<br>• **VREF− Externe**                                                           |
   | **3**     | **Valeur Numérique du CNA**      | Réglage de `DACR<4:0>` (0 → 31), Déterminant le Niveau de Tension de Sortie                                             |
   | **4**     | **Tension de Sortie**           | $`V_{OUT} = \left(\dfrac{V_{SRC+} - V_{SRC-}}{2^5}\right) \times DACR<4:0> + V_{SRC-}`$                                 |
   | **5**     | **Destination de la Sortie**     | • Entrée Positive d’un **Comparateur**<br>• Module **CAN (ADC)**<br>• Broche **DACOUT (RA2)** |


- ### Registres de Contrôle

   - #### `VREFCON1` – Contrôle de la Référence de Tension (CNA)
      <table>
       <thead>
         <tr align="center">
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
         <tr align="center">
           <td><strong>DACEN</strong></td>
           <td><strong>DACLPS</strong></td>
           <td><strong>DACOE</strong></td>
           <td>—</td>
           <td colspan="2"><strong>DACPSS&lt;1:0&gt;</strong></td>
           <td>—</td>
           <td><strong>DACNSS</strong></td>
         </tr>
       </tbody>
      </table>
   
      - **Bit 7 : `DACEN` – Activation du CNA**
         - **`0`** = **Désactivé** – Le module CNA est arrêté
         - **`1`** = **Activé** – Le module DAC est opérationnel
      
      - **Bit 6 : `DACLPS` – Sélection de la Source de Tension (Low-Power)**
         - **`0`** = **Référence Négative du DAC sélectionnée  $`V_{SRC-}`$**
         - **`1`** = **Référence Positive du DAC sélectionnée  $`V_{SRC+}`$**
      
      - **Bit 5 : `DACOE` – Activation de la Sortie CNA**
         - **`0`** = **Sortie désactivée** – La tension CNA n’est pas disponible sur la broche `DACOUT`
         - **`1`** = **Sortie activée** – La tension DAC est disponible sur la broche `DACOUT`
      
      - **Bits 3-2 : `DACPSS<1:0>` – Sélection de la Source Positive du CNA**
      
         | DACPSS1 | DACPSS0 | Source de Référence Positive  |
         | ------- | ------- | ----------------------------- |
         | 0       | 0       | **VDD**                       |
         | 0       | 1       | **VREF+**                     |
         | 1       | 0       | **Sortie FVR BUF1**           |
         | 1       | 1       | **Réservé – Ne pas utiliser** |
      
      - **Bit 0 : `DACNSS` – Sélection de la Source Négative du CNA**
         - **`0`** = **VSS**
         - **`1`** = **VREF−**

   - #### `VREFCON2` – Contrôle de la Référence de Tension (Valeur de Sortie CNA)
      <table>
       <thead>
         <tr align="center">
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
         <tr align="center">
           <td>—</td>
           <td>—</td>
           <td>—</td>
           <td colspan="5"><strong>DACR&lt;4:0&gt;</strong></td>
         </tr>
       </tbody>
      </table>
      
      - **Bits 4–0 : `DACR<4:0>` – Sélection de la Tension de Sortie du CNA**
         - Ces bits définissent la **valeur numérique** appliquée au convertisseur numérique–analogique (CNA).
         - Ils permettent de régler la tension de sortie du CNA sur **32 niveaux** possibles (5 bits).
      
           > **$`V_{OUT} = \left(\dfrac{V_{SRC+} - V_{SRC-}}{2^5}\right) \times DACR<4:0> + V_{SRC-}`$**


- ### Registres Associés

   <table>
       <thead>
           <tr align="center">
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
           <tr align="center">
               <td><strong>VREFCON0</strong></td>
               <td>FVREN</td>
               <td>FVRST</td>
               <td colspan="2">FVRS&lt;1:0&gt;</td>
               <td>—</td>
               <td>—</td>
               <td>—</td>
               <td>—</td>
           </tr>
           <tr align="center">
               <td><strong>VREFCON1</strong></td>
               <td>DACEN</td>
               <td>DACLPS</td>
               <td>DACOE</td>
               <td>—</td>
               <td colspan="2">DACPSS&lt;1:0&gt;</td>
               <td>—</td>
               <td>DACNSS</td>
           </tr>
           <tr align="center">
               <td><strong>VREFCON2</strong></td>
               <td>—</td>
               <td>—</td>
               <td>—</td>
               <td>—</td>
               <td>—</td>
               <td colspan="3">DACR&lt;4:0&gt;</td>
           </tr>
       </tbody>
   </table>


## **9. Gestion de PWM**
La **Modulation de Largeur d'Impulsion (PWM)** est une méthode permettant de fournir de l'énergie à une charge en basculant rapidement entre les états logiques ‘1’ et ‘0’. 
> Cette Fonction est Gérée par les Périphériques **Capture/Compare/PWM (CCP)**.


- ### Caractéristiques du PWM
   | **Caractéristique**     | **Description**                                                                           |
   | ----------------------- | ----------------------------------------------------------------------------------------- |
   | **Modules disponibles** | **5 modules PWM** :<br>• **3 modules ECCP** (Enhanced)<br>• **2 modules CCP** (standards) |
   | **Période**             | Durée totale d’un cycle PWM (**ON + OFF**)                                                |
   | **Rapport Cyclique**    | Pourcentage du temps où le signal est à l’état haut (**0 % à 100 %**)                     |
   | **Résolution**          | Précision du signal PWM pouvant atteindre **10 bits** (**1024 pas**)                      |

   > | <div align="center">**$`\text{Période PWM} = (PRx + 1) \times 4 \times T_{OSC} \times \text{Prescaler}`$**              |
   > | :---------------------------------------------------------------------------------------------------------------------: |
   > | <div align="center">**$`\text{Largeur d’impulsion} = (CCPRxL:CCPxCON<5:4>) \times T_{OSC} \times \text{Prescaler}`$**   |
   > | <div align="center">**$`\text{Rapport Cyclique} = \frac{CCPRxL:CCPxCON<5:4>}{4 \times (PRx + 1)}`$**                    |
   > | <div align="center">**$`\text{Résolution} = \frac{\ln \big( 4 \cdot (PRx + 1) \big)}{\ln 2} \text{bits}`$**             |



- ### Étapes de Configuration

   | **Étape** | **Action**                                   | **Description**                                                                  |
   | --------- | -------------------------------------------- | -------------------------------------------------------------------------------- |
   | **1**     | Désactiver la Sortie PWM                     | • `TRISx = 1` (Broche PWM configurée en **entrée**)                              |
   | **2**     | Sélectionner le Timer                        | • Choisir **Timer2 / Timer4 / Timer6**<br>• Configuration via `CCPTMRSx`         |
   | **3**     | Configurer la Période PWM                    | • Charger la Période dans `PRx`                                                  |
   | **4**     | Configurer le Module PWM                     | • Activer le Mode PWM dans `CCPxCON`                                             |
   | **5**     | Régler le Rapport Cyclique                   | • `CCPRxL` (8-bits MSB)<br>• `CCPxCON<5:4>` (2 bits LSB)                         |
   | **6**     | Démarrer le Timer                            | • Régler le Pré-diviseur<br>• `TMRxON = 1`                                       |
   | **7**     | Activer la sortie PWM                        | • Attendre le **Premier Débordement** du Timer<br>• `TRISx = 0` (Sortie activée) |



- ### Registres de Contrôle

   - #### `CCPxCON` – Registre de Contrôle du Module CCPx Standard (x = 1, 2, 3, 4, 5)
      <table>
         <tr>
            <td colspan="8" align="center"><strong>x = 1, 2, 3</strong></td>
         </tr>
          <tr align="center">
            <th>Bit 7</th>
            <th>Bit 6</th>
            <th>Bit 5</th>
            <th>Bit 4</th>
            <th>Bit 3</th>
            <th>Bit 2</th>
            <th>Bit 1</th>
            <th>Bit 0</th>
          </tr>
          <tr>
              <td colspan="2" align="center"><strong>PxM&lt;1:0&gt;</strong></td>
              <td colspan="2" align="center"><strong>DCxB&lt;1:0&gt;</strong></td>
              <td colspan="4" align="center"><strong>CCPxM&lt;3:0&gt;</strong></td>
          </tr>
          <tr>
            <td colspan="8" align="center"><strong>x = 4, 5</strong></td>
          </tr>
          <tr align="center">
            <td>—</td>
            <td>—</td>
            <td colspan="2"><strong>DCxB&lt;1:0&gt;</strong></td>
            <td colspan="4"><strong>CCPxM&lt;3:0&gt;</strong></td>
          </tr>
      </table>
      
      - **Bits 7-6 : `PxM<1:0>` – Configuration de la sortie PWM (ECCP uniquement)**
          - Configure le mode de sortie PWM pour les modules **ECCP (CCP1-3)**. Non présent sur **CCP4/5**.
      
      - **Bits 5-4 : `DCxB<1:0>` – Bits de Poids Faible du Rapport Cyclique PWM**
         - Ces deux bits constituent les bits de poids faible (LSb) du rapport cyclique PWM. Les 8 bits de poids fort (MSb) se trouvent dans le registre `CCPRxL`.
      
      - **Bits 3-0 : `CCPxM<3:0>` – Sélection du Mode du Module ECCPx**
         - **`11xx` = Mode PWM**


            > <table>
            >     <tr>
            >         <th colspan="10">Rapport Cyclique PWM (10 bits)</th>
            >     </tr>
            >     <tr>
            >         <td colspan="8" align="center"><strong>CCPRxL (MSB - Bits [9:2])</strong></td>
            >         <td colspan="2" align="center"><strong>DCxB&lt;1:0&gt; (LSB - Bits [1:0])</strong></td>
            >     </tr>
            >     <tr>
            >         <td align="center">Bit 9<br>(MSB)</td>
            >         <td align="center">Bit 8</td>
            >         <td align="center">Bit 7</td>
            >         <td align="center">Bit 6</td>
            >         <td align="center">Bit 5</td>
            >         <td align="center">Bit 4</td>
            >         <td align="center">Bit 3</td>
            >         <td align="center">Bit 2</td>
            >         <td align="center">Bit 1</td>
            >         <td align="center">Bit 0<br>(LSB)</td>
            >     </tr>
            > </table>



   - #### `CONFIG3H` – Configuration PWM et des Entrées/Sorties (CONFIG3H)
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td><strong>MCLRE</strong></td>
            <td>—</td>
            <td><strong>P2BMX</strong></td>
            <td><strong>T3CMX</strong></td>
            <td><strong>HFOFST</strong></td>
            <td><strong>CCP3MX</strong></td>
            <td><strong>PBADEN</strong></td>
            <td><strong>CCP2MX</strong></td>
          </tr>
        </tbody>
      </table>
      
      - **Bits associés à la sélection des sorties CCP :**
           <table>
             <thead>
               <tr align="center">
                 <th>Module CCP</th>
                 <th>Bit de Configuration</th>
                 <th>Broche I/O lorsque Bit = 0</th>
                 <th>Broche I/O lorsque Bit = 1</th>
               </tr>
             </thead>
             <tbody>
               <tr align="center">
                 <td>CCP1</td>
                 <td>—</td>
                 <td colspan="2" align="center"><strong>RB3</strong> (fixe)</td>
               </tr>
               <tr align="center">
                 <td>CCP2</td>
                 <td><strong>CCP2MX</strong></td>
                 <td><strong>RB3</strong></td>
                 <td><strong>RC1</strong></td>
               </tr>
               <tr align="center">
                 <td>CCP3</td>
                 <td><strong>CCP3MX</strong></td>
                 <td><strong>RE0</strong></td>
                 <td><strong>RB5</strong></td>
               </tr>
               <tr align="center">
                 <td>CCP4</td>
                 <td>—</td>
                 <td colspan="2" align="center"><strong>RD1</strong> (fixe)</td>
               </tr>
               <tr align="center">
                 <td>CCP5</td>
                 <td>—</td>
                 <td colspan="2" align="center"><strong>RE2</strong> (fixe)</td>
               </tr>
             </tbody>
           </table>


   - #### `CCPTMRS0` – Registre de Sélection du Timer pour PWM 0
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td colspan="2"><strong>C3TSEL&lt;1:0&gt;</strong></td>
            <td>—</td>
            <td colspan="2"><strong>C2TSEL&lt;1:0&gt;</strong></td>
            <td>—</td>
            <td colspan="2"><strong>C1TSEL&lt;1:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>
      
      - **Bits 7-6 : `C3TSEL<1:0>` – Sélection du Timer pour CCP3**
        | C3TSEL1 | C3TSEL0 | Modes Capture/Compare | Mode PWM |
        |---------|---------|------------------------|----------|
        | 0 | 0 | Timer1 | Timer2 |
        | 0 | 1 | Timer3 | Timer4 |
        | 1 | 0 | Timer5 | Timer6 |
        | 1 | 1 | **RÉSERVÉ** | |
      
      - **Bits 4-3 : `C2TSEL<1:0>` – Sélection du Timer pour CCP2**
        | C2TSEL1 | C2TSEL0 | Modes Capture/Compare | Mode PWM |
        |---------|---------|------------------------|----------|
        | 0 | 0 | Timer1 | Timer2 |
        | 0 | 1 | Timer3 | Timer4 |
        | 1 | 0 | Timer5 | Timer6 |
        | 1 | 1 | **RÉSERVÉ** | |
      
      - **Bits 1-0 : `C1TSEL<1:0>` – Sélection du Timer pour CCP1**
        | C1TSEL1 | C1TSEL0 | Modes Capture/Compare | Mode PWM |
        |---------|---------|------------------------|----------|
        | 0 | 0 | Timer1 | Timer2 |
        | 0 | 1 | Timer3 | Timer4 |
        | 1 | 0 | Timer5 | Timer6 |
        | 1 | 1 | **RÉSERVÉ** | |

   - #### `CCPTMRS1` – Registre de Sélection du Timer pour PWM 1
      <table>
        <thead>
          <tr align="center">
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
          <tr align="center">
            <td>—</td>
            <td>—</td>
            <td>—</td>
            <td>—</td>
            <td colspan="2"><strong>C5TSEL&lt;1:0&gt;</strong></td>
            <td colspan="2"><strong>C4TSEL&lt;1:0&gt;</strong></td>
          </tr>
        </tbody>
      </table>
      
      - **Bits 3-2 : `C5TSEL<1:0>` – Sélection du Timer pour CCP5**
        | C5TSEL1 | C5TSEL0 | Modes Capture/Compare | Mode PWM |
        |---------|---------|------------------------|----------|
        | 0 | 0 | Timer1 | Timer2 |
        | 0 | 1 | Timer3 | Timer4 |
        | 1 | 0 | Timer5 | Timer6 |
        | 1 | 1 | **RÉSERVÉ** | |
      
      - **Bits 1-0 : `C4TSEL<1:0>` – Sélection du Timer pour CCP4**
        | C4TSEL1 | C4TSEL0 | Modes Capture/Compare | Mode PWM |
        |---------|---------|------------------------|----------|
        | 0 | 0 | Timer1 | Timer2 |
        | 0 | 1 | Timer3 | Timer4 |
        | 1 | 0 | Timer5 | Timer6 |
        | 1 | 1 | **RÉSERVÉ** | |




- ### Registres Associés
   <table>
     <thead>
       <tr align="center">
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
         <td><strong>CCPxCON (x = 1, 2, 3)</strong></td>
         <td>—</td>
         <td>—</td>
         <td colspan="2"><strong>DCxB&lt;1:0&gt;</strong></td>
         <td colspan="4"><strong>CCPxM&lt;3:0&gt;</strong></td>
       </tr>
         <tr>
           <td><strong>CCPxCON (x = 4, 5)</strong></td>
           <td colspan="2" align="center"><strong>PxM&lt;1:0&gt;</strong></td>
           <td colspan="2" align="center"><strong>DCxB&lt;1:0&gt;</strong></td>
           <td colspan="4" align="center"><strong>CCPxM&lt;3:0&gt;</strong></td>
          </tr>
       </tr>
       <tr>
           <td><strong>CCPTMRS0</strong></td>
           <td colspan="2" align="center"><strong>C3TSEL&lt;1:0&gt;</strong></td>
           <td align="center">—</td>
           <td colspan="2" align="center"><strong>C2TSEL&lt;1:0&gt;</strong></td>
           <td align="center">—</td>
           <td colspan="2" align="center"><strong>C1TSEL&lt;1:0&gt;</strong></td>
       </tr>
       <tr>
           <td><strong>CCPTMRS1</strong></td>
           <td align="center">—</td>
           <td align="center">—</td>
           <td align="center">—</td>
           <td align="center">—</td>
           <td colspan="2" align="center"><strong>C5TSEL&lt;1:0&gt;</strong></td>
           <td colspan="2" align="center"><strong>C4TSEL&lt;1:0&gt;</strong></td>
       </tr>
     </tbody>
   </table>
   
   > Consultez les sections suivantes pour la configuration :
   > - **[Ports d’Entrée/Sortie (E/S) (`TRISx`)](#4-ports-dentréesortie-es)**
   > - **[Activation des interruptions (`PIEx`)](#registres-dactivation-pie1-à-pie5)**
   > - **[Drapeaux d'interruption (`PIRx`)](#registres-de-flags-pir1-à-pir5)**
   > - **[Priorités d'interruption (`IPRx`)](#registres-de-priorité-ipr1-à-ipr5)**
   > - **[Gestion des Timers (`TMRx`, `TxCON`, `PRx`)](#6-gestion-des-timers)**

- ### Fonctionnes Avancé MikroC
   | **Fonction**             | **Description**                                  |
   | ------------------------ | ------------------------------------------------ |
   | **`PWM1_Init(freq)`**    | **Initialise** le Module PWM1 à la Fréquence `freq`. |
   | **`PWM1_Set_Duty(val)`** | **Définit** le Rapport Cyclique du PWM.              |
   | **`PWM1_Start()`**       | **Démarre** le Signal PWM.                           |
   | **`PWM1_Stop()`**        | **Arrête** le Signal PWM.                            |





---

<h3 align="center"> 🧑🏻‍💻 | Made By : <a href="https://github.com/t4lhawi" target="_blank">Mohamed Talhaoui</a></h3>

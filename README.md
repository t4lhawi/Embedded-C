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

| Nom          | Bit 7   | Bit 6      | Bit 5  | Bit 4  | Bit 3       | Bit 2     | Bit 1     | Bit 0  |
| ------------ | ------- | ---------- | ------ | ------ | ----------- | --------- | --------- | ------ |
| **ANSELA**   | —       | —          | ANSA5  | —      | ANSA3       | ANSA2     | ANSA1     | ANSA0  |
| **CM1CON0**  | C1ON    | C1OUT      | C1OE   | C1POL  | C1SP        | C1R       | C1CH<1:0> |        |
| **CM2CON0**  | C2ON    | C2OUT      | C2OE   | C2POL  | C2SP        | C2R       | C2CH<1:0> |        |
| **LATA**     | LATA7   | LATA6      | LATA5  | LATA4  | LATA3       | LATA2     | LATA1     | LATA0  |
| **VREFCON1** | DACEN   | DACLPS     | DACOE  | —      | DACPSS<1:0> | —         | —         | DACNSS |
| **VREFCON2** | —       | —          | —      | —      | DACR<4:0>   |           |           |        |
| **HLVDCON**  | VDIRMAG | BGVST      | IRVST  | HLVDEN | HLVDC<3:0>  |           |           |        |
| **PORTA**    | RA7     | RA6        | RA5    | RA4    | RA3         | RA2       | RA1       | RA0    |
| **SLRCON**   | —       | —          | —      | SLRE   | SLRD        | SLRC      | SLRB      | SLRA   |
| **SRCON0**   | SRLEN   | SRCLK<2:0> | SRQEN  | SRNQEN | SRPS        | SRPR      |           |        |
| **SSP1CON1** | WCOL    | SSPOV      | SSPEN  | CKP    | SSPM<3:0>   |           |           |        |
| **T0CON**    | TMR0ON  | T08BIT     | T0CS   | T0SE   | PSA         | T0PS<2:0> |           |        |
| **TRISA**    | TRISA7  | TRISA6     | TRISA5 | TRISA4 | TRISA3      | TRISA2    | TRISA1    | TRISA0 |

> - — = emplacements non implémentés, lus comme ‘0’.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**
>    - `n` = bit le plus significatif (à gauche) du champ
>    - `m` = bit le moins significatif (à droite) du champ

- ### Registres associés au PORTB

Voici la **réécriture du tableau en français**, en format texte clair (Markdown) :

| Nom         | Bit 7       | Bit 6       | Bit 5       | Bit 4   | Bit 3       | Bit 2      | Bit 1       | Bit 0  |
| ----------- | ----------- | ----------- | ----------- | ------- | ----------- | ---------- | ----------- | ------ |
| **ANSELB**  | —           | —           | ANSB5       | ANSB4   | ANSB3       | ANSB2      | ANSB1       | ANSB0  |
| **ECCP2AS** | CCP2ASE     | CCP2AS<2:0> |             |         | PSS2AC<1:0> |            | PSS2BD<1:0> |        |
| **CCP2CON** | P2M<1:0>    |             | DC2B<1:0>   |         |             | CCP2M<3:0> |             |        |
| **ECCP3AS** | CCP3ASE     | CCP3AS<2:0> |             |         | PSS3AC<1:0> |            | PSS3BD<1:0> |        |
| **CCP3CON** | P3M<1:0>    |             | DC3B<1:0>   |         |             | CCP3M<3:0> |             |        |
| **INTCON**  | GIE/GIEH    | PEIE/GIEL   | TMR0IE      | INT0IE  | RBIE        | TMR0IF     | INT0IF      | RBIF   |
| **INTCON2** | RBPU        | INTEDG0     | INTEDG1     | INTEDG2 | —           | TMR0IP     | —           | RBIP   |
| **INTCON3** | INT2IP      | INT1IP      | —           | INT2IE  | INT1IE      | —          | INT2IF      | INT1IF |
| **IOCB**    | IOCB7       | IOCB6       | IOCB5       | IOCB4   | —           | —          | —           | —      |
| **LATB**    | LATB7       | LATB6       | LATB5       | LATB4   | LATB3       | LATB2      | LATB1       | LATB0  |
| **PORTB**   | RB7         | RB6         | RB5         | RB4     | RB3         | RB2        | RB1         | RB0    |
| **SLRCON**  | —           | —           | —           | SLRE(1) | SLRD(1)     | SLRC       | SLRB        | SLRA   |
| **T1GCON**  | TMR1GE      | T1GPOL      | T1GTM       | T1GSPM  | $`T1GGO/\bar{DONE}`$  | T1GVAL     | T1GSS<1:0>  |        |
| **T3CON**   | TMR3CS<1:0> |             | T3CKPS<1:0> |         | T3SOSCEN    | $`\bar{T3SYNC}`$     | T3RD16      | TMR3ON |
| **T5CON**   | TMR5GE      | T5GPOL      | T5GTM       | T5GSPM  | $`T5GGO/\bar{DONE}`$  | T5GVAL     | T5GSS<1:0>  |        |
| **TRISB**   | TRISB7      | TRISB6      | TRISB5      | TRISB4  | TRISB3      | TRISB2     | TRISB1      | TRISB0 |
| **WPUB**    | WPUB7       | WPUB6       | WPUB5       | WPUB4   | WPUB3       | WPUB2      | WPUB1       | WPUB0  |

> - — = emplacements non implémentés, lus comme ‘0’.
> - Les **bits grisés ne sont pas utilisés pour PORTB**.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**
>    - `n` = bit le plus significatif (à gauche) du champ
>    - `m` = bit le moins significatif (à droite) du champ



- ### Registres associés au PORTC

| Nom          | Bit 7       | Bit 6       | Bit 5       | Bit 4   | Bit 3       | Bit 2      | Bit 1       | Bit 0  |
| ------------ | ----------- | ----------- | ----------- | ------- | ----------- | ---------- | ----------- | ------ |
| **ANSELC**   | ANSC7       | ANSC6       | ANSC5       | ANSC4   | ANSC3       | ANSC2      | —           | —      |
| **ECCP1AS**  | CCP1ASE     | CCP1AS<2:0> |             |         | PSS1AC<1:0> |            | PSS1BD<1:0> |        |
| **CCP1CON**  | P1M<1:0>    |             | DC1B<1:0>   |         |             | CCP1M<3:0> |             |        |
| **ECCP2AS**  | CCP2ASE     | CCP2AS<2:0> |             |         | PSS2AC<1:0> |            | PSS2BD<1:0> |        |
| **CCP2CON**  | P2M<1:0>    |             | DC2B<1:0>   |         |             | CCP2M<3:0> |             |        |
| **CTMUCONH** | CTMUEN      | —           | CTMUSIDL    | TGEN    | EDGEN       | EDGSEQEN   | IDISSEN     | CTTRIG |
| **LATC**     | LATC7       | LATC6       | LATC5       | LATC4   | LATC3       | LATC2      | LATC1       | LATC0  |
| **PORTC**    | RC7         | RC6         | RC5         | RC4     | RC3         | RC2        | RC1         | RC0    |
| **RCSTA1**   | SPEN        | RX9         | SREN        | CREN    | ADDEN       | FERR       | OERR        | RX9D   |
| **SLRCON**   | —           | —           | —           | SLRE(1) | SLRD(1)     | SLRC       | SLRB        | SLRA   |
| **SSP1CON1** | WCOL        | SSPOV       | SSPEN       | CKP     | SSPM<3:0>   |            |             |        |
| **T1CON**    | TMR1CS<1:0> |             | T1CKPS<1:0> |         | T1SOSCEN    | $`\bar{T1SYNC}`$     | T1RD16      | TMR1ON |
| **T3CON**    | TMR3CS<1:0> |             | T3CKPS<1:0> |         | T3SOSCEN    | $`\bar{T3SYNC}`$     | T3RD16      | TMR3ON |
| **T3GCON**   | TMR3GE      | T3GPOL      | T3GTM       | T3GSPM  | $`T3GGO/\bar{DONE}`$  | T3GVAL     | T3GSS<1:0>  |        |
| **T5CON**    | TMR5CS<1:0> |             | T5CKPS<1:0> |         | T5SOSCEN    | $`\bar{T5SYNC}`$     | T5RD16      | TMR5ON |
| **TRISC**    | TRISC7      | TRISC6      | TRISC5      | TRISC4  | TRISC3      | TRISC2     | TRISC1      | TRISC0 |
| **TXSTA1**   | CSRC        | TX9         | TXEN        | SYNC    | SENDB       | BRGH       | TRMT        | TX9D   |

> - — = **emplacements non implémentés, lus comme ‘0’**.
> - Les **bits grisés ne sont pas utilisés pour PORTC**.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**
>    - `n` = bit le plus significatif (à gauche) du champ
>    - `m` = bit le moins significatif (à droite) du champ

- ### Registres associés au PORTD

| Nom          | Bit 7    | Bit 6  | Bit 5     | Bit 4  | Bit 3     | Bit 2      | Bit 1  | Bit 0  |
| ------------ | -------- | ------ | --------- | ------ | --------- | ---------- | ------ | ------ |
| **ANSELD¹**  | ANSD7    | ANSD6  | ANSD5     | ANSD4  | ANSD3     | ANSD2      | ANSD1  | ANSD0  |
| **BAUDCON2** | ABDOVF   | RCIDL  | DTRXP     | CKTXP  | BRG16     | —          | WUE    | ABDEN  |
| **CCP1CON**  | P1M<1:0> |        | DC1B<1:0> |        |           | CCP1M<3:0> |        |        |
| **CCP2CON**  | P2M<1:0> |        | DC2B<1:0> |        |           | CCP2M<3:0> |        |        |
| **CCP4CON**  | —        | —      | DC4B<1:0> |        |           | CCP4M<3:0> |        |        |
| **LATD¹**    | LATD7    | LATD6  | LATD5     | LATD4  | LATD3     | LATD2      | LATD1  | LATD0  |
| **PORTD¹**   | RD7      | RD6    | RD5       | RD4    | RD3       | RD2        | RD1    | RD0    |
| **RCSTA2**   | SPEN     | RX9    | SREN      | CREN   | ADDEN     | FERR       | OERR   | RX9D   |
| **SLRCON¹**  | —        | —      | —         | SLRE   | SLRD      | SLRC       | SLRB   | SLRA   |
| **SSP2CON1** | WCOL     | SSPOV  | SSPEN     | CKP    | SSPM<3:0> |            |        |        |
| **TRISD¹**   | TRISD7   | TRISD6 | TRISD5    | TRISD4 | TRISD3    | TRISD2     | TRISD1 | TRISD0 |

> - — = **emplacements non implémentés, lus comme ‘0’**.
> - **`<n:m>` → on prend tous les bits du bit n jusqu’au bit m, inclus.**
>    - `n` = bit le plus significatif (à gauche) du champ
>    - `m` = bit le moins significatif (à droite) du champ

- ### Registres associés au PORTE

| Nom         | Bit 7 | Bit 6   | Bit 5   | Bit 4   | Bit 3 | Bit 2   | Bit 1   | Bit 0   |
| ----------- | ----- | ------- | ------- | ------- | ----- | ------- | ------- | ------- |
| **ANSELE¹** | —     | —       | —       | —       | —     | ANSE2   | ANSE1   | ANSE0   |
| **INTCON2** | $`\bar{RBPU}`$  | INTEDG0 | INTEDG1 | INTEDG2 | —     | TMR0IP  | —       | RBIP    |
| **LATE**   | —     | —       | —       | —       | —     | LATE2   | LATE1   | LATE0   |
| **PORTE**   | —     | —       | —       | —       | RE3   | RE2    | RE1    | RE0    |
| **SLRCON**  | —     | —       | —       | SLRE   | SLRD | SLRC    | SLRB    | SLRA    |
| **TRISE**   | WPUE3 | —       | —       | —       | —     | TRISE2 | TRISE1 | TRISE0 |

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

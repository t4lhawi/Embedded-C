# **Sommaire :**

* **[Manipulation des Bits](#1-manipulation-des-bits)**
* **[Microcontrôleur PIC18F](#2-microcontrôleur-pic18f)**
* **[Ports d’Entrée/Sortie (E/S)](#3-ports-dentréesortie-es)**
* **[Gestion des Interruptions](#4-gestion-des-interruptions)**
* **[Gestion des Timers](#5-gestion-des-timers)**

---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-C" target="_blank">Lien de Programmation en Langage C</a></h3>

---

## **1. Manipulation des Bits**

* C’est un **système électronique autonome** exécutant un programme dédié à une tâche spécifique.
* Il fonctionne avec des **ressources limitées** : mémoire, énergie, puissance.
* Il doit souvent réagir **en temps réel**.
* Le **PIC18F** est un microcontrôleur typique utilisé dans ces systèmes.

---

## **2. Microcontrôleur PIC18F**

* Langage **rapide** et **efficace** pour le bas niveau.
* Permet d’accéder directement aux **registres matériels**.
* Compatible avec le compilateur **MPLAB XC8**.
* Utilisé pour configurer et piloter les **périphériques internes** (GPIO, timers, UART, etc.).

```c
#include <xc.h>        // Bibliothèque principale Microchip
#define _XTAL_FREQ 8000000   // Définir la fréquence du quartz
```

---

## **3. Ports d’Entrée/Sortie (E/S)**

 Utiliser des **tailles fixes** (bibliothèque `<stdint.h>`) pour maîtriser la mémoire.

| Type       | Taille  | Exemple d’usage                   |
| ---------- | ------- | --------------------------------- |
| `uint8_t`  | 8 bits  | Lecture d’un port GPIO            |
| `uint16_t` | 16 bits | Valeur d’un Timer                 |
| `uint32_t` | 32 bits | Compteur logiciel                 |
| `volatile` | —       | Variable modifiée par le matériel |

```c
volatile uint8_t bouton;     // variable modifiée par interruption
uint16_t compteurTemps;      // compteur local
```

---

## **4. Gestion des Interruptions**

Chaque périphérique du PIC18F est contrôlé par des **registres** :

* `TRISx` → définit la direction (entrée/sortie).
* `PORTx` → lit les niveaux logiques.
* `LATx`  → écrit sur les sorties.

- **Opérations sur les bits :**

```c
REG |= (1 << n);   // Met le bit n à 1
REG &= ~(1 << n);  // Met le bit n à 0
REG ^= (1 << n);   // Inverse le bit n
if (REG & (1 << n)) { ... } // Teste le bit n
```

---

## **5. Gestion des Timers**

Le PIC18F contient plusieurs zones mémoire :

* **Programme (Flash)** → contient le code C compilé.
* **RAM (Données)** → variables temporaires.
* **EEPROM** → données conservées après coupure d’alimentation.

Les périphériques sont mappés en mémoire, accessibles via des **pointeurs volatiles**.

```c
#define REGISTRE (*(volatile uint8_t*)0xF80)
```

---

<h3 align="center"> 🧑🏻‍💻 | Made By : <a href="https://github.com/mohamedtalhaouii" target="_blank">Mohamed Talhaoui</a></h3>

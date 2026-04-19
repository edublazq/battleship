# ⚓ BATTLESHIP - Proyecto de Programación

> Un juego clásico de Batalla Naval implementado en C++ con orientación a objetos.

---

## 👤 Información del Alumno

| Campo | Valor |
|-------|-------|
| **Nombre** | Eduaro Blázquez |
| **Email** | edblazqu@student.42madrid.com |
| **Institución** | 42 Madrid |

---

## 🚀 Compilación y Ejecución

### Compilar el proyecto
```bash
make
```

### Ejecutar el juego
```bash
./battleship
```

### Limpiar archivos objeto
```bash
make clean
```

### Limpiar todo (objetos + ejecutable)
```bash
make fclean
```

### Recompilar desde cero
```bash
make re
```

---

## 📁 Estructura del Proyecto

```
battleship/
├── 📄 Makefile              # Configuración de compilación
├── 📄 README.md             # Este archivo
├── include/                 # Headers (.hpp)
│   ├── battleship.hpp       # Headers principales
│   ├── board.hpp            # Clase Board (tablero)
│   ├── box.hpp              # Clase Box (casilla)
│   ├── game.hpp             # Clase Game (lógica del juego)
│   ├── ship.hpp             # Clase Ship (barco)
│   └── types.hpp            # Tipos y constantes
└── src/                     # Archivos fuente (.cpp)
    ├── main.cpp             # Entrada principal
    ├── error_handler.cpp    # Manejo de errores
    └── class/
        ├── board.cpp        # Implementación Board
        ├── box.cpp          # Implementación Box
        ├── game.cpp         # Implementación Game
        └── ship.cpp         # Implementación Ship
```

### 🏛️ Clases Principales

| Clase | Descripción |
|-------|-------------|
| **Box** | Representa una casilla del tablero (agua, barco, impacto) |
| **Ship** | Representa un barco (posición, tamaño, orientación, hits) |
| **Board** | Tablero 10×10 con barcos y lógica de disparo |
| **Game** | Controla flujo del juego (turnos, fin de juego) |

---

## 🎮 Reglas del Juego

- 🎯 **Objetivo**: Hundir todos los barcos del rival
- 📏 **Tablero**: 10×10 casillas (columnas 0-9, filas 0-9)
- 🚢 **Barcos**:
  - 1 Portaaviones (tamaño 4)
  - 2 Acorazados (tamaño 3)
  - 3 Destructores (tamaño 2)
  - 4 Lanchas (tamaño 1)
- 💥 **Turnos**: Jugador dispara → Ordenador dispara
- 📍 **Entrada**: Coordenadas en formato `col-fila` (ej: `2-7`)

### Indicadores del Tablero

| Símbolo | Significado |
|---------|------------|
| `~` | Agua sin disparos |
| `O` | Agua donde disparaste |
| `X` | Barco impactado |
| `B` | Tu barco (solo visible en tu tablero) |

---

## 🏗️ Decisiones de Diseño

### 1. **Estructura de Datos**
- **Tablero**: `vector<vector<Box>>` para acceso O(1) a cualquier casilla
- **Barcos**: `list<Ship>` para gestión flexible
- ✅ **Ventaja**: Acceso eficiente y inserción/eliminación rápida

### 2. **Validación de Colocación**
- ❌ Los barcos **NO** pueden solaparse (misma casilla)
- 📏 Separación **mínima de 1 casilla** en todas direcciones (incluidas diagonales)
- 🔍 Algoritmo: Búsqueda por vecindad 3×3 alrededor de cada casilla

```cpp
// Valida 8 celdas alrededor de cada punto del barco
for (int ny = y - 1; ny <= y + 1; ny++)
    for (int nx = x - 1; nx <= x + 1; nx++)
        if (_board[nx][ny].getStatus() == SHIP)
            return false;
```

### 3. **Colocación Aleatoria**
- Reintentos hasta **1000 intentos** por barco
- Regenera el tablero en cada llamada a `randPutShip()`
- ✅ Evita acumulación de barcos en llamadas repetidas

### 4. **Detección de Barco Hundido**
- 🔗 Búsqueda de conectividad (BFS) para encontrar componentes
- Un barco está hundido si **no hay casillas `SHIP` sin impacto** conectadas
- ✅ Soporta barcos de cualquier forma (aunque actualmente lineales)

```cpp
// Si no hay SHIP sin impactar conectada → barco hundido
if (isSunk(_computerBoard, pos))
    cout << "Le has hundido un barco!";
```

### 5. **Estados de Casillas**
```cpp
enum e_status {
    WATER,          // Agua sin disparar
    SHIP,           // Barco sin impacto
    SHOOTED,        // Barco impactado
    SHOOTED_WATER   // Agua disparada
}
```

### 6. **Visibilidad Selectiva**
- **Tu tablero** (`flag=true`): Muestra todos los barcos
- **Tablero enemigo** (`flag=false`): Oculta barcos (muestra `~`)
- ✅ Mantiene la jugabilidad justa

### 7. **Entrada del Jugador**
- Formato simple: `col-fila` (ej: `2-7`)
- Validación: Solo acepta dígitos 0-9
- ✅ Interfaz clara y robusta

### 8. **Orientación de Barcos**
```cpp
enum e_orientation {
    HORIZONTAL,  // Extiende en eje X
    VERTICAL     // Extiende en eje Y
}
```

### 9. **Manejo Centralizado de Errores**
```cpp
void puterror(const char *s) {
    cerr << BOLD << RED << s << RESET << endl;
}
```
- Función centralizada para consistencia
- Mensajes en rojo para destacar

### 10. **Inicialización Robusta**
- `srand(time(nullptr))` para variedad en barcos
- Mensaje de bienvenida con reglas al inicio
- ✅ Experiencia de usuario mejorada

---

## 🔧 Compilador y Flags

```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude
```

| Flag | Descripción |
|------|-------------|
| `-Wall` | Muestra todos los warnings |
| `-Wextra` | Muestra warnings adicionales |
| `-Werror` | Trata warnings como errores |
| `-Iinclude` | Ruta a headers personalizados |

---

## 🎨 Características

✨ **Interfaz con colores ANSI**
- Rojo para errores y mensajes importantes
- Verde para tablero y estructura
- Negrita para títulos

🎲 **Barcos colocados aleatoriamente**
- Diferente en cada partida
- Aleatorio para ambos jugadores

🤖 **Ordenador inteligente**
- Dispara con coordenadas aleatorias
- Jugabilidad equilibrada

💾 **Validaciones robustas**
- Evita solapes entre barcos
- Comprobación de límites del tablero
- Prevención de disparos duplicados

---

## 📊 Estadísticas del Proyecto

| Métrica | Valor |
|---------|-------|
| **Líneas de código** | ~400 |
| **Clases** | 4 |
| **Métodos públicos** | ~20 |
| **Archivos fuente** | 7 |
| **Archivos header** | 5 |

---

## 🚦 Flujo del Juego

```
1. Mostrar reglas y bienvenida
   ↓
2. Inicializar barcos (jugador + ordenador)
   ↓
3. Loop del juego:
   ├─ Turno del jugador (input 'col-fila')
   ├─ Mostrar tablero del ordenador (sin barcos)
   ├─ Turno del ordenador (disparo aleatorio)
   ├─ Mostrar tablero del jugador
   └─ Comprobar si alguien ganó
   ↓
4. Mostrar resultado final
```

---

## 📝 Notas Adicionales

- 🎯 Sin persistencia de datos entre partidas (todo en memoria)
- 🔄 El programa es determinista si se usa la misma semilla de `rand`
- 🧪 Compilado y probado con `c++` (clang++)
- 📖 Sigue convenciones de la escuela 42 Madrid

---

## 👨‍💻 Cómo Jugar

```bash
$ make
$ ./battleship
```

Sigue las instrucciones en pantalla:
1. Verás tus barcos (marcados con `B`)
2. Introduce coordenadas para disparar: `X-Y` (ej: `3-4`)
3. ¡Intenta hundir todos los barcos del ordenador antes que tú!
4. Gana quien hunda primero todos los barcos rivales

---

## 📚 Recursos Utilizados

### 🏫 42 School
Este proyecto implementa conceptos fundamentales aprendidos en **42 Madrid**:
- Programación orientada a objetos en C++
- Gestión de memoria y estructuras de datos
- Normas de código limpio y convenciones de 42
- Uso de Makefiles y compilación
- Debugging y manejo de errores

### 🤖 Inteligencia Artificial
Se ha utilizado IA en las siguientes areas:

**📝 Generación de Documentación**
- README.md: Estructura, diseño y formateo
- Mensajes de texto en español: Reglas del juego, outputs de usuario
- Documentación técnica: Explicación de decisiones de diseño

**🧪 Pruebas y Validación**
- Pruebas profundas de lógica de colocación de barcos
- Casos de borde: solapamientos, límites del tablero, validaciones
- Validación de detección de hundimiento
- Análisis de flujo del juego

**💡 Optimización**
- Sugerencias de algoritmos eficientes
- Refactorización de código
- Mejora de UX con colores y mensajes

---

**¡Que empiece la batalla! ⚓**

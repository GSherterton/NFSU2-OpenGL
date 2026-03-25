# Contributing to NFSU2-OpenGL

## Build

```bash
# First time
meson setup build
meson compile -C build

# After changes
meson compile -C build

# Run
./build/src/nfsu2-opengl
```

**Dependencies (Linux):**
```bash
sudo apt install meson build-essential libgl-dev libglu-dev freeglut3-dev
```

## Adding a New Module

1. Create `include/ModuleName.h` and `src/ModuleName.cpp`
2. Add `'ModuleName.cpp'` to the `sources` list in `src/meson.build`

## Naming Conventions


| Category | Style | Examples |
|---|---|---|
| Classes | PascalCase | `Camera`, `Garage`, `Texture` |
| Methods / free functions | camelCase | `drawFloor()`, `loadTextures()` |
| Member variables | `m_` prefix + camelCase | `m_width`, `m_position`, `m_wallTex` |
| Local variables | camelCase | `hasTexture`, `pillarWidth` |
| Parameters | camelCase | `wallPath`, `floorPath` |
| Global variables | lowercase | `camera`, `garage` |
| Macros / preprocessor constants | UPPER_SNAKE_CASE | `DARK_GRAY`, `BLUISH_GRAY` |

> **Exception:** single-letter names (`x`, `y`, `z`, `w`, `h`) are acceptable in mathematical/coordinate contexts and standard GLUT callback signatures.

## Code Style

- One class per file
- Local transformations always wrapped in `glPushMatrix()` / `glPopMatrix()`
- All scene objects must be centered near the origin `(0, 0, 0)`

## Formatting

The project uses clang-format. A `.clang-format` file is provided at the root.

Format a file:
```bash
clang-format -i src/MyFile.cpp
```

Check without modifying:
```bash
clang-format --dry-run --Werror src/MyFile.cpp
```

> **Note:** `glBegin`/`glEnd` vertex blocks and `glPushMatrix`/`glPopMatrix` sections in `Garage.cpp` are wrapped in `// clang-format off/on` to preserve their columnar alignment. Keep those guards when adding new geometry.

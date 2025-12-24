# QMK Firmware Agent Guidelines

## Build Commands

### Compilation
- `qmk compile -kb splitkb/kyria/rev2 -km amerocu` - Build the keyboard

### Testing
- **Run single test**: `make -C builddefs build_test TEST=<test_name>` where `<test_name>` is the test directory name (e.g., `basic`, `combo`, `caps_word`)
- **Build system**: Tests use Google Test framework in `tests/` directory
- **Test structure**: Each test requires `test.mk`, `config.h`, and `test_*.cpp` files

### C Code Style
- **Indentation**: 4 spaces (soft tabs, no tabs)
- **Brace Style**: Modified One True Brace Style
  - Opening brace: end of same line
  - Closing brace: lined up with first character of opening statement
  - Always include optional braces
- **Comments**: Use C-style `/* */` comments liberally to explain decisions
- **Line Length**: No strict limit, wrap at ~76 columns if needed
- **Headers**: Use `#pragma once` instead of include guards
- **Preprocessor**: Accept both `#ifdef` and `#if defined()`, prefer latter for new code

### Naming Conventions
- **Functions**: `snake_case` (e.g., `conway_spawn_in()`)
- **Variables**: `snake_case` (e.g., `conway_spawn_coordinates`)
- **Constants**: `UPPER_SNAKE_CASE` (e.g., `CONWAY_ENABLE`)
- **Macros**: `UPPER_SNAKE_CASE` (e.g., `MATRIX_POS_X`)
- **Types**: `snake_case` for structs, `UPPER_SNAKE_CASE` for typedefs

### File Organization
- **Keymaps**: Place in `keyboards/keyboard/keymaps/name/`
- **User Code**: Place in `users/username/` for shared functionality
- **Tests**: Place in `tests/category/` with `test.mk`, `config.h`, `test_*.cpp`
- **Headers**: Use `#pragma once` at start, include necessary headers

### QMK-Specific Patterns
- **Keymaps**: Use `LAYOUT()` macro with proper matrix definitions
- **Process Records**: Implement `process_record_user()` for custom key handling
- **Layers**: Define layer enums with descriptive names (`_QWERTY`, `_SYM`, etc.)
- **Features**: Enable via `rules.mk` with conditional compilation (`ifeq`)
- **Split Keyboards**: Handle master/slave synchronization properly

### Error Handling
- **Return Values**: Use `true`/`false` for success/failure in process functions
- **Validation**: Check parameters and return early on invalid input
- **Debugging**: Use `CONSOLE_ENABLE=yes` and `dprintf()` for debug output

### Testing Guidelines
- **Unit Tests**: Use Google Test framework in `tests/` directory
- **Test Structure**: Each test requires `test.mk`, `config.h`, and `test_*.cpp` files
- **Mocking**: Use `TestDriver` and `KeymapKey` for keyboard testing
- **Assertions**: Use `EXPECT_*` and `ASSERT_*` macros appropriately

## Important Notes
- Always match existing code style in files you modify
- Use `// clang-format off`/`on` around sensitive macros like LAYOUT definitions
- QMK uses custom build system - check `Makefile` and `builddefs/` for details
- Many features are conditionally compiled - check `rules.mk` files
- Split keyboards require special handling for master/slave coordination

## We are working into!

- users/amerocu
- keyboards/splitkb/kyria/keymaps/amerocu
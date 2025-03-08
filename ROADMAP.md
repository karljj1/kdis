# Roadmap

Near horizon work is focused on C++ modernization and improved unit test coverage, while preserving
[standards compliance](https://www.sisostandards.org/news/678685/Publication-of-SISO-REF-010-V33-Enumerations.htm).

### Backlog

| Sequence | GitHub # | Title | Sequence reason |
|---|---|---|---|
| 1 | #64 | introduce BoundedLengthString to help replace 2 major C arrays | early work on #63, ready for review/mainlining |
| 2 | #43 | Compiler warnings | low hanging fruit, these produce a lot of unwanted noise in Codecov |
| 3 | #63 | prefer std::array instead of fixed-length C arrays in data members | will facilitate #49 |
| 4 | #49 | move towards always initializing an object | will facilitate #22 |
| 5 | #22 | enum class instead of enum | |

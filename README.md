# EndStream

## About

This C++ program allows programmers to write little-endian or big-endian data to and from std::stream, std::istream and std::ostream.

As an example, the programmer can write:

```
uint16_t foo;
EndStream estream(fin, EndStream.BIG_ENDIAN);
estream >> foo;
```
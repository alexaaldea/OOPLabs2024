#include <stdio.h>
#include "Map.h"
int main()
{
    Map<int, const char*> m;
    m.Set(10, "C++");
    m.Set(20, "test");
    m.Set(30, "Poo");
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto entry = *it;
        printf("Index:%zu, Key=%d, Value=%s\n", entry.index, entry.key, entry.value);
    }
    m.Set(20, "result");
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto entry = *it;
        printf("Index:%zu, Key=%d, Value=%s\n", entry.index, entry.key, entry.value);
    }
    return 0;
}

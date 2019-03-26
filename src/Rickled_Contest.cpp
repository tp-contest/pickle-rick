#include <iostream>
#include "TextFile.h"
#include "CommonFileBase.h"

int main() {
    CommonFileBase CFB1;

    {
        TextFile drops;
        drops.setText("drop");

        TextFile bass("bass");

        CFB1.insert(drops, "drop.txt");
        CFB1.insert(bass, "bass.txt");
    }

    TextFile drops;
    CFB1.get(drops, "drop.txt");
    std::cout << drops.getText() << std::endl;
}
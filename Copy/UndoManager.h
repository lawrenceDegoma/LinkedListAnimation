//
// Created by Lawrence Degoma on 5/19/24.
//

#ifndef TEXTINPUTBOX_UNDOMANAGER_H
#define TEXTINPUTBOX_UNDOMANAGER_H


#include <vector>
#include <string>

class UndoManager {
private:
    std::vector<std::string> history;
public:
    void saveState(const std::string& state);
    std::string undo();
};


#endif //TEXTINPUTBOX_UNDOMANAGER_H

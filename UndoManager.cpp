//
// Created by Lawrence Degoma on 5/19/24.
//

#include "UndoManager.h"

void UndoManager::saveState(const std::string& state) {
    history.push_back(state);
}

std::string UndoManager::undo() {
    if (history.empty()) {
        return "";
    }
    history.pop_back();
    return history.empty() ? "" : history.back();
}
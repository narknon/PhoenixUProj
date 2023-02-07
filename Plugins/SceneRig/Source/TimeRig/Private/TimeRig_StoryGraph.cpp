#include "TimeRig_StoryGraph.h"

class UTimeRig_StoryGraphNode;

void UTimeRig_StoryGraph::Print(bool ToConsole, bool ToScreen) {
}

void UTimeRig_StoryGraph::GetNodesByLevel(int32 Level, TArray<UTimeRig_StoryGraphNode*>& Nodes) {
}

int32 UTimeRig_StoryGraph::GetLevelNum() const {
    return 0;
}

UTimeRig_StoryGraph::UTimeRig_StoryGraph() {
    this->bEdgeEnabled = true;
    this->bPersistent = true;
}


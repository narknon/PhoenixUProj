#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeRig_StoryGraph.generated.h"

class UTimeRig_StoryGraphEdge;
class UTimeRig_StoryGraphNode;
class UWorld;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRig_StoryGraph : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRig_StoryGraphNode*> RootNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRig_StoryGraphNode*> AllNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRig_StoryGraphEdge*> AllEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEdgeEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPersistent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> StageLevels;
    
    UTimeRig_StoryGraph();
    UFUNCTION(BlueprintCallable)
    void Print(bool ToConsole, bool ToScreen);
    
    UFUNCTION(BlueprintCallable)
    void GetNodesByLevel(int32 Level, TArray<UTimeRig_StoryGraphNode*>& Nodes);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevelNum() const;
    
};


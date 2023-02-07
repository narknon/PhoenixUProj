#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FXAutoTriggerGroupDefinitionAsset.generated.h"

class UFXAutoTriggerDefinitionAsset;
class UFXAutoTriggerPrerequisiteBase;

UCLASS(Blueprintable)
class FXUTIL_API UFXAutoTriggerGroupDefinitionAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerPrerequisiteBase*> GroupPrerequisites;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerDefinitionAsset*> Definitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRunWithGlobalActors;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UFXAutoTriggerDefinitionAsset*> GroupNames;
    
public:
    UFXAutoTriggerGroupDefinitionAsset();
};


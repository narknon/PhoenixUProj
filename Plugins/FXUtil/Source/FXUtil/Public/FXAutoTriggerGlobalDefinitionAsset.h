#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FXAutoTriggerGlobalDefinitionAsset.generated.h"

class UFXAutoTriggerDefinitionAsset;
class UFXAutoTriggerGroupDefinitionAsset;
class UFXAutoTriggerPrerequisiteBase;

UCLASS(Blueprintable)
class FXUTIL_API UFXAutoTriggerGlobalDefinitionAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerDefinitionAsset*> GlobalDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerGroupDefinitionAsset*> GroupDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerPrerequisiteBase*> GlobalPrerequisites;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UFXAutoTriggerDefinitionAsset*> GlobalNames;
    
public:
    UFXAutoTriggerGlobalDefinitionAsset();
};


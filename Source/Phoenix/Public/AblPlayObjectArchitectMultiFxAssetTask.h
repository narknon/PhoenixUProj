#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AblPlayMultiFxAssetBaseTask.h"
#include "AblPlayObjectArchitectMultiFxAssetTask.generated.h"

class UAblObjectArchitectTagChooser;

UCLASS(Blueprintable, EditInlineNew)
class UAblPlayObjectArchitectMultiFxAssetTask : public UAblPlayMultiFxAssetBaseTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BaseObjectArchitectTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblObjectArchitectTagChooser*> TagChoosers;
    
    UAblPlayObjectArchitectMultiFxAssetTask();
};


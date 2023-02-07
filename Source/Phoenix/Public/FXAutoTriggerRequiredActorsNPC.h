#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsBase.h"
#include "FXAutoTriggerRequiredActorsNPC.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsNPC : public UFXAutoTriggerRequiredActorsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ExcludeActorTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludePlayerCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludePlayerLeadNPC;
    
    UFXAutoTriggerRequiredActorsNPC();
};


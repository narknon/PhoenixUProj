#pragma once
#include "CoreMinimal.h"
#include "Actor_SpawnFromDOVBase.h"
#include "Actor_SpawnFromDOVWithName.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_SpawnFromDOVWithName : public UActor_SpawnFromDOVBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DOVActorName;
    
    UActor_SpawnFromDOVWithName();
};


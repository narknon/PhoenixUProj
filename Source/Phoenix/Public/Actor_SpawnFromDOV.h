#pragma once
#include "CoreMinimal.h"
#include "WorldActorReference.h"
#include "Actor_SpawnFromDOVBase.h"
#include "Actor_SpawnFromDOV.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_SpawnFromDOV : public UActor_SpawnFromDOVBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldActorReference DOVActorReference;
    
    UActor_SpawnFromDOV();
};


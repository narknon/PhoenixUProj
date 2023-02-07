#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_DOVWithName.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_DOVWithName : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DOVActorName;
    
    UActor_DOVWithName();
};


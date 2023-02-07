#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "Templates/SubclassOf.h"
#include "OptionActorIsAClassConsideration.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsAClassConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorClass;
    
    UOptionActorIsAClassConsideration();
};


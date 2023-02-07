#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "Templates/SubclassOf.h"
#include "SelfActorIsAClassConsideration.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorIsAClassConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorClass;
    
    USelfActorIsAClassConsideration();
};


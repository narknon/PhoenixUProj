#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "Templates/SubclassOf.h"
#include "SelfActorHasActorComponent.generated.h"

class UActorComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorHasActorComponent : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActorComponent> ActorComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverseResult;
    
    USelfActorHasActorComponent();
};


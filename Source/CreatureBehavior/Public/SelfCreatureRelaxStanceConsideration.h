#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ECreatureStance.h"
#include "SelfCreatureRelaxStanceConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureRelaxStanceConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance Stance;
    
public:
    USelfCreatureRelaxStanceConsideration();
};


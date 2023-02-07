#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfSurfaceMaxAngleConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfSurfaceMaxAngleConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAngle;
    
public:
    USelfSurfaceMaxAngleConsideration();
};


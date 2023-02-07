#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "Chaos/ChaosEngineInterface.h"
#include "SelfOnSurfaceConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfOnSurfaceConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPhysicalSurface> DesiredSurface;
    
public:
    USelfOnSurfaceConsideration();
};


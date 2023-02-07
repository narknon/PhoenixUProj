#pragma once
#include "CoreMinimal.h"
#include "WindAffectedOrientToTickingComponent.h"
#include "WindAffectedScales.h"
#include "WindAffectedScaleOrientToTickingComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindAffectedScaleOrientToTickingComponent : public UWindAffectedOrientToTickingComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindAffectedScales WindScaling;
    
    UWindAffectedScaleOrientToTickingComponent();
};


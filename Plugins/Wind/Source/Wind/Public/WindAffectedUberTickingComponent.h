#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WindAffectedParameters -FallbackName=WindAffectedParameters
#include "WindAffectedParameters.h"
#include "WindAffectedScaleOrientToTickingComponent.h"
#include "WindAffectedUberTickingComponent.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindAffectedUberTickingComponent : public UWindAffectedScaleOrientToTickingComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WindAffectedMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindAffectedParameters WindAffectedParameters;
    
    UWindAffectedUberTickingComponent();
};


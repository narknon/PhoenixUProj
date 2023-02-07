#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WindAffectedParameters -FallbackName=WindAffectedParameters
#include "WindAffectedParameters.h"
#include "WindAffectedTickingComponent.h"
#include "WindAffectedMaterialTickingComponent.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindAffectedMaterialTickingComponent : public UWindAffectedTickingComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WindAffectedMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindAffectedParameters WindAffectedParameters;
    
    UWindAffectedMaterialTickingComponent();
};


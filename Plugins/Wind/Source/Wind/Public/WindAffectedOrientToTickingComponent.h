#pragma once
#include "CoreMinimal.h"
#include "WindAffectedTickingComponent.h"
#include "WindAffectedOrientToTickingComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindAffectedOrientToTickingComponent : public UWindAffectedTickingComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToWind;
    
    UWindAffectedOrientToTickingComponent();
};


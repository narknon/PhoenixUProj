#pragma once
#include "CoreMinimal.h"
#include "WindAffectedComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WindAffectedComponent -FallbackName=WindAffectedComponent
#include "WindAffectedTickingComponent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindAffectedTickingComponent : public UWindAffectedComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTickBeforeBeginPlay;
    
    UWindAffectedTickingComponent();
};


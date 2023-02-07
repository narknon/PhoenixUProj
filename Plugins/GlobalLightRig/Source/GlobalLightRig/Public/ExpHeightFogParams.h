#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ExpHeightFogParams.generated.h"

class UExpHeightFogTransmuter;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParams : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExpHeightFogTransmuter* Transmuter;
    
    UExpHeightFogParams();
};


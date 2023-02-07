#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HogsmeadeMaterialFade.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UHogsmeadeMaterialFade : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* Material;
    
    UHogsmeadeMaterialFade();
};


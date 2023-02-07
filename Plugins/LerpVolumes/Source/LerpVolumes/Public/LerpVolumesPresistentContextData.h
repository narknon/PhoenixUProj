#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LerpVolumesPresistentContextData.generated.h"

class ULerpVolumesPresistentContextDataBase;

UCLASS(Blueprintable)
class LERPVOLUMES_API ULerpVolumesPresistentContextData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, ULerpVolumesPresistentContextDataBase*> DataMap;
    
    ULerpVolumesPresistentContextData();
};


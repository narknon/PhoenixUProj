#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RadialForceData.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class URadialForceData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoreActors;
    
    URadialForceData();
};


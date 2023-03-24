#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Marker.generated.h"

UCLASS(Blueprintable)
class AMarker : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName UniqueName;
    
public:
    AMarker(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    FName GenerateUniqueName(FName InBaseName);
    
};


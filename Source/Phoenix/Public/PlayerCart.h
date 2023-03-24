#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "PlayerCart.generated.h"

UCLASS(Blueprintable)
class APlayerCart : public APawn {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform DismountLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform CompanionDismountLocation;
    
    APlayerCart(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateCartPositionAndRotation(const FVector& InNewLocation, const FRotator& InNewRotation, const FVector& InVelocity);
    
};


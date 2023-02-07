#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "FoliageRemoverActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFoliageRemoverActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BoxSize;
    
public:
    UFoliageRemoverActorComponent();
    UFUNCTION(BlueprintCallable)
    void SetBoxSize(const FVector& Size);
    
    UFUNCTION(BlueprintCallable)
    void RespawnFoliage();
    
    UFUNCTION(BlueprintCallable)
    void RemoveFoliage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetBoxInWorldSpace() const;
    
};


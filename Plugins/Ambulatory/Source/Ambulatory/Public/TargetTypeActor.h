#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TargetTypeBase.h"
#include "TargetTypeActor.generated.h"

class AActor;

UCLASS(Blueprintable)
class AMBULATORY_API UTargetTypeActor : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeActor();
    UFUNCTION(BlueprintCallable)
    void SetTargetActor(AActor* InTargetActor);
    
    UFUNCTION(BlueprintCallable)
    void SetSocketName(FName InSocketName);
    
    UFUNCTION(BlueprintCallable)
    void SetActorOffset(FVector InActorOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTargetActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetSocketName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetActorOffset() const;
    
};


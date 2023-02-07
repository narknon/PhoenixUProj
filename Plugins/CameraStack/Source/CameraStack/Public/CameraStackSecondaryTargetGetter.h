#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackSecondaryTargetGetter.generated.h"

class AActor;
class UCameraStack;

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class CAMERASTACK_API UCameraStackSecondaryTargetGetter : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CommitTime;
    
    UCameraStackSecondaryTargetGetter();
    UFUNCTION(BlueprintCallable)
    void Update(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTargetLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetTargetBoundingCylinder(FVector& OutCenterLocation, float& OutHalfHeight, float& OutRadius) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTargetActor() const;
    
    UFUNCTION(BlueprintCallable)
    void Activate(UCameraStack* InList);
    
};


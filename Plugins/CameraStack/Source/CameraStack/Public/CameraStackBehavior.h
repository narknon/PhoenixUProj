#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraData.h"
#include "CameraStackBehavior.generated.h"

class ACameraStackActor;
class UCameraStack;

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class CAMERASTACK_API UCameraStackBehavior : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCameraStack> CurrentList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DisableCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPaused;
    
public:
    UCameraStackBehavior();
    UFUNCTION(BlueprintCallable)
    void SetPaused(bool bInPaused);
    
    UFUNCTION(BlueprintCallable)
    void SetDisabled(bool bInDisabled, bool bForce);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPaused() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSecondsActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPreviousValues(FCameraData& OutData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACameraStackActor* GetOwner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStack* GetBehaviorList() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllPreviousValues(FCameraData& OutData, bool bInUseUnblendedStackValues) const;
    
};


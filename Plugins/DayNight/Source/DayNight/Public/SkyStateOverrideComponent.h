#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DayNightSkyStateOverrideInterface.h"
#include "SkyStateOverrideComponent.generated.h"

class USkyStateOverride;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API USkyStateOverrideComponent : public UActorComponent, public IDayNightSkyStateOverrideInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyStateOverride* SkyStateOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ComponentLerpAlpha;
    
public:
    USkyStateOverrideComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void Valid(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable)
    void SetLerpAlpha(float LerpAlpha);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsEnabled(bool& bEnable) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void HasLerpAlpha(bool& bHasLerpAlpha) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLerpAlpha(float& LerpAlpha) const;
    
    UFUNCTION(BlueprintCallable)
    void DisableLerpAlpha();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void CanUseLerpAlpha(bool& bUseLerpAlpha) const;
    
    
    // Fix for true pure virtual functions not being implemented
};


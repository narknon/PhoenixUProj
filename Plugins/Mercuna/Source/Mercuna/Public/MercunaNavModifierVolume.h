#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Volume.h"
#include "MercunaNavUsageTypes.h"
#include "MercunaNavModifierVolume.generated.h"

class AMercunaNavOctree;

UCLASS(Blueprintable)
class MERCUNA_API AMercunaNavModifierVolume : public AVolume {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CostMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CostMultipler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavUsageTypes UsageTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMercunaNavOctree* NavOctree;
    
public:
    AMercunaNavModifierVolume();
    UFUNCTION(BlueprintCallable)
    void SetUsageTypes(const FMercunaNavUsageTypes& NewUsageTypes);
    
    UFUNCTION(BlueprintCallable)
    void SetSize(FVector Size);
    
    UFUNCTION(BlueprintCallable)
    void SetLocationAndSize(FVector Location, FVector Size);
    
    UFUNCTION(BlueprintCallable)
    void SetLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetCostMultiplier(float NewCostMultiplier);
    
    UFUNCTION(BlueprintCallable)
    void AddToOctree(AMercunaNavOctree* NewNavOctree);
    
};


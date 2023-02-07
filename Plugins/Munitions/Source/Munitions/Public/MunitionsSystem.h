#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "MunitionImpactData.h"
#include "MunitionToInstigatorData.h"
#include "Templates/SubclassOf.h"
#include "MunitionsSystem.generated.h"

class AActor;
class AMunitionType_Base;
class APawn;

UCLASS(Blueprintable)
class MUNITIONS_API UMunitionsSystem : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AMunitionType_Base*> MunitionList;
    
public:
    UMunitionsSystem();
    UFUNCTION(BlueprintCallable)
    static AMunitionType_Base* SpawnMunition(TSubclassOf<AMunitionType_Base> MunitionClass, AActor* MunitionOwner, APawn* Instigator, const FVector& SourcePos);
    
    UFUNCTION(BlueprintCallable)
    static void SetMunitionImpactFailed();
    
    UFUNCTION(BlueprintCallable)
    static void SendSpellMadeContact(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData);
    
    UFUNCTION(BlueprintCallable)
    static void SendMunitionImpactDamage(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData);
    
    UFUNCTION(BlueprintCallable)
    static bool SendMunitionImpactCombined(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData);
    
    UFUNCTION(BlueprintCallable)
    static void SendMunitionImpact(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData);
    
    UFUNCTION(BlueprintCallable)
    static void MunitionToInstigator(UObject* Owner, UObject* Caller, const FMunitionToInstigatorData& mtoIData);
    
    UFUNCTION(BlueprintCallable)
    static void DestroySpawnedMunition(AMunitionType_Base* Munition);
    
};


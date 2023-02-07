#pragma once
#include "CoreMinimal.h"
#include "EStandardManagedPriority.h"
#include "SpellTool.h"
#include "DisillusionmentSpellTool.generated.h"

class AActor;
class UMaterialInterface;
class UMultiFX2_Base;
class UObject;

UCLASS(Blueprintable)
class ADisillusionmentSpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DisillusionmentMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DisillusionmentFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FailedFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> EndMuzzleFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSlowWalk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> TalentStrings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    ADisillusionmentSpellTool();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisillusionmentStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisillusionmentEnd();
    
    UFUNCTION(BlueprintCallable)
    bool DeactivateDisillusionment(EStandardManagedPriority Priority, UObject* InInstigator);
    
protected:
    UFUNCTION(BlueprintCallable)
    void CasterHealthZero(AActor* InActor);
    
public:
    UFUNCTION(BlueprintCallable)
    bool ActivateDisillusionment(EStandardManagedPriority Priority, UObject* InInstigator);
    
};


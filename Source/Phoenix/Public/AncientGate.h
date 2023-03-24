#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "AncientGate.generated.h"

class UMaterialParameterCollection;
class UMaterialSwapComponent;
class USceneComponent;

UCLASS(Blueprintable)
class AAncientGate : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* m_CurrentLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* m_CurrentRight;
    
    AAncientGate(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void SetAllCollisions(TArray<AActor*> i_RedTarget, TArray<AActor*> i_BlueTarget, TMap<AActor*, bool> i_PassThroughCheck, bool bIsRed);
    
    UFUNCTION(BlueprintCallable)
    void SetActorCollision(AActor* i_Actor, TEnumAsByte<ECollisionResponse> i_Response, TMap<AActor*, bool> i_PassThroughCheck);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Rotating();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Recall(AActor* Who, AActor* Pedestal);
    
private:
    UFUNCTION(BlueprintCallable)
    void MaterialSetup(TArray<AActor*>& i_Target, TMap<UMaterialSwapComponent*, AActor*>& i_Materials, FLinearColor& i_Color);
    
protected:
    UFUNCTION(BlueprintCallable)
    void MaterialCutoutFlip(TMap<UMaterialSwapComponent*, AActor*> i_RedMaterials, TMap<UMaterialSwapComponent*, AActor*> i_BlueMaterials, UMaterialParameterCollection* i_Collection, bool bIsRedSide);
    
    UFUNCTION(BlueprintCallable)
    void InitialMaterialSetup(TArray<AActor*> i_RedTarget, TArray<AActor*> i_BlueTarget, TMap<UMaterialSwapComponent*, AActor*>& i_RedMaterials, TMap<UMaterialSwapComponent*, AActor*>& i_BlueMaterials, FLinearColor i_RedColor, FLinearColor i_BlueColor);
    
    UFUNCTION(BlueprintCallable)
    void AncientGateSetup(USceneComponent* i_ArrowComponent, USceneComponent* i_LeftPoint, USceneComponent* i_RightPoint, FLinearColor i_RedColor, FLinearColor i_BlueColor);
    
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ELocalStencilMaterialMode.h"
#include "LocalStencilEffect.h"
#include "LocalStencilComponentBase.generated.h"

class AActor;
class UStaticMesh;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilComponentBase : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshScaleFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TranslucentSortPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetTranslucentSortPriority;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLocalStencilEffect CurrentEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBox WorldObjectBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FadeInAge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FadeOutAge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ELocalStencilMaterialMode MaterialMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEffectActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bStencilManagerLock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFadingOut;
    
public:
    ULocalStencilComponentBase();
    UFUNCTION(BlueprintCallable)
    bool StartLocalStencilEffect(FLocalStencilEffect Effect);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void LocalStencilEffectIsRunning(bool& bIsRunning, FLocalStencilEffect& RunningEffect);
    
    UFUNCTION(BlueprintCallable)
    bool EndLocalStencilEffect();
    
    UFUNCTION(BlueprintCallable)
    static void ActorStartLocalStencilEffect(AActor* Actor, FLocalStencilEffect Effect, bool& Success);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorLocalStencilEffectIsRunning(AActor* Actor, bool& bIsRunning, FLocalStencilEffect& RunningEffect);
    
    UFUNCTION(BlueprintCallable)
    static void ActorEndLocalStencilEffect(AActor* Actor, bool& Success);
    
};


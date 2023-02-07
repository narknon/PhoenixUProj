#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/InputComponent.h"
#include "InputWatcherComponent.generated.h"

class AActor;
class UBaseWatcher;
class UGameLogicObject;
class UInputToGameLogic;
class UStickFlickWatcherRecord;
class UWatcherRecord;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CONTROLMAPPER_API UInputWatcherComponent : public UInputComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBaseWatcher*> Watchers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UInputToGameLogic*> InputToGameLogicMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBaseWatcher*> UpdateWatcherList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameLogicObject* GameLogicObject;
    
public:
    UInputWatcherComponent();
    UFUNCTION(BlueprintCallable)
    UGameLogicObject* GetGameLogicObject();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetFlickDirection(AActor* Owner, UStickFlickWatcherRecord* StickFlickWatcherRecord);
    
    UFUNCTION(BlueprintCallable)
    static void FlushQueuedActionsOnOwner(AActor* Owner, UWatcherRecord* InWatcherRecord);
    
    UFUNCTION(BlueprintCallable)
    void FlushQueuedActions(UWatcherRecord* InWatcherRecord);
    
};


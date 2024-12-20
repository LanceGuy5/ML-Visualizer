#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QMenuBar;
class QMenu;
class QAction;
class QLabel;
class QPushButton;

enum class State { MENU, NEW };

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void set_state(State s);
  void render_state();

private:
  /* STATE MACHINE */
  State state = State::MENU;

  /* RENDERING TITLE */
  QLabel *title;
  QLabel *subTitle;

  /* BUTTON STUFF */
  QPushButton *newButton;

  /* MENU STUFF */
  void setupMenu();
  QMenuBar *menuBar;
  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *helpMenu;

  QAction *newAction;
  QAction *openAction;
  QAction *exitAction;
  QAction *cutAction;
  QAction *copyAction;
  QAction *pasteAction;
  QAction *aboutAction;

private slots:
  void showAboutDialog();
  void newButtonPressed();
};

#endif // MAIN_WINDOW_H
